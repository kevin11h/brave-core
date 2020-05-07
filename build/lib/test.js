const path = require('path')

const config = require('../lib/config')
const util = require('../lib/util')

const getTestBinary = (suite) => {
  return (process.platform === 'win32') ? `${suite}.exe` : suite
}

const getTestsToRun = (config, suite) => {
  testsToRun = [suite]
  if (suite === 'brave_unit_tests') {
    testsToRun.push('brave_rewards_unit_tests')
    if (config.targetOS !== 'android') {
      testsToRun.push('brave_installer_unittests')
    } else {
      testsToRun.push('bin/run_brave_public_test_apk')
    }
  }
  return testsToRun
}

const test = (suite, buildConfig = config.defaultBuildConfig, options) => {
  config.buildConfig = buildConfig
  config.update(options)

  const braveArgs = [
    '--enable-logging'
  ]

  // Android doesn't support --v
  if (config.targetOS !== 'android') {
    braveArgs.push('--v=' + options.v)
  }

  if (options.filter) {
    braveArgs.push('--gtest_filter=' + options.filter)
  }

  if (options.output) {
    braveArgs.push('--gtest_output=xml:' + options.output)
  }

  if (options.disable_brave_extension) {
    braveArgs.push('--disable-brave-extension')
  }

  if (options.single_process) {
    braveArgs.push('--single_process')
  }

  if (options.test_launcher_jobs) {
    braveArgs.push('--test-launcher-jobs=' + options.test_launcher_jobs)
  }

  // Build the tests
  const actualSuite = (suite === 'brave_unit_tests') ? 'all_unit_tests' : suite
  util.run('ninja', ['-C', config.outputDir, actualSuite], config.defaultOptions)

  if (config.targetOS === 'ios') {
    util.run(path.join(config.outputDir, "iossim"), [
      path.join(config.outputDir, `${suite}.app`),
      path.join(config.outputDir, `${suite}.app/PlugIns/${suite}_module.xctest`)
    ], config.defaultOptions)
  } else {
    // Fix the tests
    util.run('ninja', ['-C', config.outputDir, "fix_all_tests"], config.defaultOptions)
    // Run the tests
    getTestsToRun(config, suite).forEach((testSuite) => {
      if (options.output) {
        braveArgs.splice(braveArgs.indexOf('--gtest_output=xml:' + options.output, 1))
        braveArgs.push('--gtest_output=xml:${testBinary}.xml')
      }
      util.run(path.join(config.outputDir, getTestBinary(testSuite)), braveArgs, config.defaultOptions)
    })
  }
}

module.exports = test
