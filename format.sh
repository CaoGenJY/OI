#!/bin/bash

echo "以下文件将被删除"

find . -type f \
  ! -path "./.vscode/*" \
  ! -path "./.cph-ng/*" \
  ! -path "./.git/*" \
  ! -name "*.cpp" \
  ! -name "*.sh"

read -p "是否继续执行？(y/n): " confirm

if [[ "$confirm" == "y" ]] ; then
    echo "删除中..."
else
    echo "操作已取消。"
    exit 1
fi

find . -type f \
  ! -path "./.vscode/*" \
  ! -path "./.cph-ng/*" \
  ! -path "./.git/*" \
  ! -name "*.cpp" \
  ! -name "*.sh" \
  -delete

  echo "操作已完成"