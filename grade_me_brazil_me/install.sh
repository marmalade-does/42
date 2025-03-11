#!/bin/bash

#
# EXEC: source <(curl https://raw.githubusercontent.com/allandantas21/GradeMe_42Rio/main/install.sh)
#

REPO_URL="https://github.com/allandantas21/GradeMe_42Rio.git"
REPO_DIR="GradeMe_42Rio"

if [ ! -d "$REPO_DIR" ]; then
  git clone "$REPO_URL"
fi

make -C "$REPO_DIR"
