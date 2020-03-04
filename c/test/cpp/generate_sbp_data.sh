#!/usr/bin/env bash

echo "Converting json files in /json_data to sbp files in /sbp_data"
rm -r ./sbp_data/*
for file_path in ./json_data/*.json; do
  file_name=$(basename "$file_path" .json)
  cat $file_path | json2sbp > "sbp_data/${file_name}.sbp"
done
echo "All done, please commit the results!"
