#!/bin/bash
python lib/ez_setup.py
cd lib/selenium-2.37.2
python setup.py install
cd -
apt-get install python-mysqldb
