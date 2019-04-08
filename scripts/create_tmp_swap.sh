#!/bin/bash


#
# Create temporary 1GB swap.
# NOTE: This script requires sudo
#


CUR_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
SWAP_FILENAME="swapfile"
SWAP_FILE="$CUR_DIR/$SWAP_FILENAME"

swapoff $SWAP_FILE
rm -rf $SWAP_FILE
dd if=/dev/zero of=$SWAP_FILE bs=1M count=1024
chmod 600 $SWAP_FILE
mkswap $SWAP_FILE
swapon $SWAP_FILE
