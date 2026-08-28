{
    files = {
        "src/main.cpp"
    },
    values = {
        "/usr/bin/g++",
        {
            "-m64",
            "-fvisibility=hidden",
            "-fvisibility-inlines-hidden",
            "-O3",
            "-std=c++17",
            "-Isrc",
            "-DNDEBUG"
        }
    },
    depfiles_format = "gcc",
    depfiles = "main.o: src/main.cpp src/file_ops.hpp src/datatypes.hpp  src/ClassicalMachineLearningModels/linear_regression.hpp  src/ClassicalMachineLearningModels/helpers/helpers.hpp  src/ClassicalMachineLearningModels/helpers/../../datatypes.hpp  src/ClassicalMachineLearningModels/../datatypes.hpp\
"
}