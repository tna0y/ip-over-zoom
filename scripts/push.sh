#!/usr/bin/env bash
set -xeuo pipefail
git add .
git status 
read
git commit -m "$@"
git push
