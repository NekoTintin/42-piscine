git ls-files -io --exclude-standard $(git rev-parse --show-toplevel) | rev | cut -d "/" -f 1 | rev
