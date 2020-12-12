#!/bin/bash

git tag custom/$(date "+%Y-%m-%d-%H-%M")-before
git push origin --tags

git checkout master
git fetch upstream
git pull upstream master

git push origin master
git checkout custom

git merge master
git push origin HEAD

git tag custom/$(date "+%Y-%m-%d-%H-%M")-after
git push origin --tags
