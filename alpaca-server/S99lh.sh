#!/bin/sh
cd ~/alpaca/server
git stash
git pull
qmake
make
./alpaca-server
