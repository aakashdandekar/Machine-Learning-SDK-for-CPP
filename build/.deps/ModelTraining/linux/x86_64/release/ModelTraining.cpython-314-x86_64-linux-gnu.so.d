{
    values = {
        "/usr/bin/g++",
        {
            "-shared",
            "-m64",
            "-fPIC",
            "-L/usr/lib",
            "-s",
            "-lpython3.14",
            "-lssl",
            "-lcrypto"
        }
    },
    files = {
        "build/.objs/ModelTraining/linux/x86_64/release/src/bindings.cpp.o"
    }
}