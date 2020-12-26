#!/bin/bash

git tag custom/$(date "+%Y-%m-%d-%H-%M")-before

git checkout master
git fetch upstream
git pull upstream master

git push origin master
git checkout custom

git merge master

git tag custom/$(date "+%Y-%m-%d-%H-%M")-after

# git push origin HEAD
# git push origin --tags
