# my_world
## C and CSFML terraformer program.
The project's goal is to display a map and edit it at runtime. The map is a wireframed map with tiles that are squares having all the same size. The ground must be altered by raising, lowering or tilting tiles.

### Demo
![alt text](https://github.com/GreenDjango/my_world/blob/master/demo_1.gif "Demo")
### Big map
![alt text](https://github.com/GreenDjango/my_world/blob/master/demo_2.gif "Demo big map")
### Bonus 3d editor
![alt text](https://github.com/GreenDjango/my_world/blob/master/demo_3.gif "Demo bonus")

My_world is inspired by [Tycoon Terrain for Unity3D](https://www.youtube.com/watch?v=AgINNA1tB_w).

## Controls
Keyboard | Info
--- | ---
**P** | zoom in
**M** | zoom out
**ARROW** | move map
**T** | print texture
**R** | rotate texture
**C** | contains 3 tools, which can be activated with the left and the right click
**C 1** | up or down face point
**C 2** | up or down face
**C 3** | rest or up to max face

## Authorized functions
All the functions from the CSFML and the math library are allowed. From the libc, here is the full list of authorized functions:
+ malloc
+ free
+ memset
+ (s)rand
+ getline
+ (f)open
+ (f)read
+ (f)close
+ (f)write
+ opendir
+ readdir
+ closedir
