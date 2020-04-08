#!/bin/bash

#
#	A simple script used to mount a partition (usally USB flash drive)
#	to the 'mnt' directory of the users home directory.
#
#	NOTE: Script was created under the assumption that the partition uses the VFAT file system.
#

sudo mount -o uid=`id -u`,gid=`id -g`,fmask=177,dmask=077 $1 ~/mnt
