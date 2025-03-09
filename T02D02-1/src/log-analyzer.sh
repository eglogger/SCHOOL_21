#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Wrong input!"
    exit 1
fi

LOG_FILE=$1

TOTAL_RECORDS=$(wc -l < "$LOG_FILE")

UNIQUE_FILES=$(awk -F" - " '{print $1}' "$LOG_FILE" | sort -u | wc -l)

HASH_CHANGES=$(awk -F" - " '{print $4}' "$LOG_FILE" | sort -u | wc -l)

echo "$TOTAL_RECORDS $UNIQUE_FILES $((HASH_CHANGES-UNIQUE_FILES))"