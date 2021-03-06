| **Platform** | **Master** |
| -------- | ----- |
| Linux | [![Build Status](https://travis-ci.org/IdrisMiles/ImplicitSkinning.svg?branch=master)](https://travis-ci.org/IdrisMiles/ImplicitSkinning) |

# Implicit Skinning
This is my Advanced Graphics Software Development Techniques assignment for Bournemouth University.
This project is my implementation of implicit skinning based on ["Implicit Skinning: Real-Time Skin Deformation with Contact Modeling"](http://rodolphe-vaillant.fr/pivotx/templates/projects/implicit_skinning/implicit_skinning.pdf). 
The project is written in C++ and uses CUDA to speed up evaluation of field functions as well as perform skinning computations
## How it Works
* A model is segmented into mesh parts, each mesh part is determined by the underlying bone structure and the bone weights for each vertex. 
* Then sample points on the surface of each mesh part are generated. 
* From these sample points a compactly supported [0-1] field function is generated, the 0.5 iso-surface of this field function closely approximates the original mesh part.
* During animation each mesh part is rigidly transformed by the corresponding bone. The field function is also transformed.
* The transformed field functions are combined using composition operators that combines two field functions into one.
* Once all the fields are composed together we are left with the global field, whose 0.5 iso-surface approximates the whole mesh.
* During the skinning process we initially apply Linear Blend Weight (LBW) skinning, then we march the deformed vertices along the gradient of the global field.
* We apply some smoothing and eventually are left with an implicit skinned mesh.

## Status
### Completed
* :white_check_mark: Linear Blend Weight skinning implemented on the GPU
* :white_check_mark: Marching Cube ported to GPU
* :white_check_mark: Generate fields for each mesh part.
* :white_check_mark: Pre-compute fields into 3D textures.
* :white_check_mark: Generate global field on the GPU.
* :white_check_mark: Evaluate global field on the GPU.
* :white_check_mark: Visualise Iso-Surface.
* :white_check_mark: Implemented Max composition operator.
* :white_check_mark: Implemented Vertex Projection, Tangential Relaxation according to paper.
* :white_check_mark: Implemented Onering neighbourhood
* :white_check_mark: Implemented Mean Value Coordinates to generate onering weights for Tangential Relaxation.
### Issues
* :x: Still need to implement gradient based composition operator.
* :warning: Vertex projection, marching vertex in global field producing strange results, think this is an issue with the evaluation of the global fields gradient.
* :warning: Tangential Relaxation, not producing smooth results. 


## Docs
To build the documentation using Doxygen, run:
```bash
doxygen Doxyfile
```

## Supported Platforms
This project has been tested on the following Platforms

| **OS** | **Version** |
| ---- | ------- |
| Ubuntu | 16.04 |
| RedHat | 7.2 |

Requires an NVIDIA CUDA enabled GPU to utilize parallel optimizations.


## Dependencies
| **Name** | **Version** |
| ---- | ------- |
| [CUDA](https://developer.nvidia.com/cuda-downloads) | >= 7 |
| [GLM](http://glm.g-truc.net/0.9.8/index.html)| >= 0.9.2 (tested 0.9.8) |
| [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page)| >= 3.2.9 |
| [ASSIMP](http://www.assimp.org/) | >= 3.3.1 |


## Build
### Linux
```bash
git clone https://github.com/IdrisMiles/ImplicitSkinning.git
cd ImplicitSkinning
qmake
make clean
make
```

## Run
### Linux
```bash
cd ImplicitSkinning/bin
./ImplicitSkinning
```

## Usage
Load in an animation file.
### Accepted Animation Files Format
* In theory any formats ASSIMP can load
* .dae (COLLADA) - tested


### Key Operations
| **Key** | **Operation** |
| ---- | ------- |
| **W** | Toggle skinned mesh wireframe |
| **E** | Toggle rendering skinned mesh |
| **R** | Toggle rendering Iso-Surface of global field |
| **T** | Toggle between Implicit Skinning and Linear Blend Weight Skinning |


## Issues


## Version
This is version 0.1.0


## Author
Idris Miles


## License
