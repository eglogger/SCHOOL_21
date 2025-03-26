#!/bin/bash

if [ "$#" -ne 3 ]; then
    echo "Wrong input!"
    exit 1
fi

FILE_PATH=$1
SEARCH_STRING=$2
REPLACEMENT_STRING=$3
LOG_FILE="files.log"

if grep -q "$SEARCH_STRING" "$FILE_PATH"; then
    sed -i " " "s/$SEARCH_STRING/$REPLACEMENT_STRING/g" "$FILE_PATH"

    FILE_HASH=$(shasum -a 256 "$FILE_PATH" | awk '{ print $1 }')

    TIMESTAMP=$(date "+%Y %b %d %H:%M:%S %Y")

    FILE_SIZE=$(wc -c "$FILE_PATH" | awk '{print $1}')

    echo "$FILE_PATH - $FILE_SIZE - $TIMESTAMP - $FILE_HASH - sha256" >> "$LOG_FILE"
    echo "Success!"
else
    echo "String not found!"
fi