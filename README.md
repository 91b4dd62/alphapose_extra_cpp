# alphapose_extra_cpp

<hr>

## build

> conda create --name openmmlab python=3.8 -y
> 
> conda activate openmmlab
> 
> pip install -r requirements.txt
> 
> mkdir build .\
> 
> cd build
> 
> cmake ..
> 
> cmake --build .\
> 
> cd Debug 
> 
> mkdir Frame
> 
> mkdir Result
> 
> mkdir ResultFrame
> 
> mkdir Video
> 
> #Now you need to download the file MMEdu.zip on https://1drv.ms/u/s!AsPQ7qinc7sreXDZS90x5BRjFvQ?e=TyQCD4 and unzip it on the "Debug" path
> 
> #You also need to download process.py on https://1drv.ms/u/s!AsPQ7qinc7srePEFzgO7y-rs-9E?e=cetLrQ to this path
> 
> #Put the target video in path "Video" and double click the exe to start the process.
The Program uses CPU to process for default.

## If you want to change it into CUDA or other device, change the 8th line of process.py "device='cpu'" into others
