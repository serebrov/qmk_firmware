#!/bin/bash

SCRIPT_PATH=`dirname $0`
ROOT_PATH=$SCRIPT_PATH/..

$ROOT_PATH/bin/qmk flash -kb mitosis -km mitosis_mini
