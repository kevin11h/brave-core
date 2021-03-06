#!/usr/bin/env python
import sys
import subprocess
import os.path
import os


def main():
    args = sys.argv[1:]
    replace_cc_arg(args)
    if 'CC_WRAPPER' in os.environ:
        args = [os.environ['CC_WRAPPER']] + args
    cc_retcode = subprocess.call(args)
    return cc_retcode


def replace_cc_arg(args):
    # Interested in -c <path>.cc
    try:
        if sys.platform == 'win32':
            index_c = args.index('/c')
        else:
            index_c = args.index('-c')
    except Exception:
        # no -c or /c so just skip
        return

    if 0 == len(args) or index_c == len(args) - 1:
        # Something wrong, we have -c but have no path in the next arg
        # Just then give all to cc as is
        return
    index_path = index_c + 1

    path_cc = args[index_path]

    # Get the absolute *.cc path
    abs_path_cc = os.path.abspath(path_cc)

    # Get this `brave/src/brave/script/redirect-cc.py` script absolute location
    this_py_path = os.path.realpath(__file__)

    # Get the original chromium dir location, triple parent of current
    # redirect-cc.py
    chromium_original_dir = os.path.abspath(os.path.join(this_py_path,
                                                         os.pardir, os.pardir,
                                                         os.pardir))

    if len(chromium_original_dir) >= len(abs_path_cc) + 1:
        # Could not get original chromium src dir
        return

    # Relative path
    rel_path = abs_path_cc[len(chromium_original_dir) + 1:]

    # Filter away out and out_x86
    # Maybe this dir can be queried from env variable instead of hardcoding
    OUT_DIR_NAMES = ['out', 'out_x86']
    start_dir = rel_path.split(os.sep)[0]
    if start_dir in OUT_DIR_NAMES:
        # Don't even try to substitute path for auto-generated cc
        return

    # Build possible brave/chromium_src_path
    brave_path = os.path.join(chromium_original_dir, 'brave', 'chromium_src',
                              rel_path)
    if os.path.isfile(brave_path):
        # Okay, we can replace
        args[index_path] = brave_path


if __name__ == '__main__':
    sys.exit(main())
