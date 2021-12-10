# Unit tests

Unit tests for the CPP files are defined in this folder.

## Dependencies

`json2sbp`, which can be installed by following the instructions [here](https://github.com/swift-nav/libsbp/tree/master/haskell#install-from-hackage).

## Test data

The json test data is stored and edited inside the `json_data` folder.

The unit tests run on the `.sbp` files stored inside the `sbp_data` folder, which are directly generated from the `.json` files by running the following commands:
```
cd ./c/test/cpp
./generate_sbp_data.sh
```
One should NOT modify the files within `sbp_data` directly, but should instead modify the corresponding `json_data` file and then regenerate the `.sbp` files and commit the results.
