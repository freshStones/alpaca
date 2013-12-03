#!/bin/sh
cd ~/alpaca/server
git pull
qmake
make
./alpaca-server
