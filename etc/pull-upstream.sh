#!/bin/bash

git checkout master
git fetch upstream
git pull upstream master

git push origin master
git checkout custom

git merge master
git push origin HEAD
