# Install instructions for sai p4_16 backend
  
Following:  [p4c build instructions](https://github.com/p4lang/p4c/edit/master/README.md).
## clone p4c repo, with the following branch
[p4c repo](https://github.com/p4lang/p4c/).

```
git clone https://github.com/p4lang/p4c.git  
git checkout 6d265b2d15b927db522c08f36a60fe23784e8357
git submodule update --init --recursive
```

## link sai p4 compiler extention
2. in p4c/extensions (make new dir if needed)
 '''ln -s <sai_p4_compiler_git_path>/backend/ sai'''

## Build. 
Building should also take place in a subdirectory named `build`.  
 in p4c repo:
    
    ./bootstrap.sh 

    [optional: remove all other backends by adding -DENABLE_BMV2=OFF -DENABLE_EBPF=OFF -DENABLE_P4TEST=OFF -DENABLE_P4C_GRAPHS=OFF to cmake in bootstrap.sh]	

	cd build
	make -j4
    sudo make install


# compile P4 program:  
p4c-sai PATH_TO_P4 -o OUTPUT_JSON 
(all output will go in the same dir as json)
for example, compiling example.p4:  
```
mkdir -p sai_p4_compiler/output/example
p4c-sai sai_p4_compiler/p4src/example/example.p4 -o sai_p4_compiler/output/example/example.json
```
all output will be spilled to sai_p4_compiler/output/example/
