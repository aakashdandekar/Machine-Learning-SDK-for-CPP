{
    values = {
        "/usr/bin/g++",
        {
            "-m64",
            "-fPIC",
            "-fvisibility=hidden",
            "-fvisibility-inlines-hidden",
            "-O3",
            "-std=c++17",
            "-Isrc",
            "-isystem",
            "/home/aakashdandekar/.xmake/packages/p/pybind11/v3.0.4/51aaece52c0a4fd8be0d27ab6ac97aa5/include",
            "-isystem",
            "/usr/include/python3.14",
            "-DNDEBUG"
        }
    },
    files = {
        "src/bindings.cpp"
    },
    depfiles = "bindings.o: src/bindings.cpp  src/ClassicalMachineLearningModels/linear_regression.hpp  src/ClassicalMachineLearningModels/helpers/helpers.hpp  src/ClassicalMachineLearningModels/helpers/../../datatypes.hpp  src/ClassicalMachineLearningModels/../datatypes.hpp\
",
    depfiles_format = "gcc"
}