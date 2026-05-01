find . -type f \
  ! -path "./.vscode/*" \
  ! -path "./.cph-ng/*" \
  ! -path "./.git/*" \
  ! -name "*.cpp" \
  ! -name "README.md" \
  ! -name "*.sh" \
  -delete