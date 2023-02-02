from MMEdu import MMPose # 导入mmpose模块
from pathlib import Path
import shutil
import sys
model = MMPose(backbone='SCNet') # 实例化mmpose模型
FrameDir=Path("./Frame")
i=0
FrameNum=sys.argv[1]
while(i<=int(FrameNum)):
    #print(path)
    img="./Frame/raw"+str(i)+".jpg"
    #print(pathstr)
    result = model.inference(img=img,device='cpu',show=False,work_dir="./ResultFrame",name=str(i)) # 在CPU上进行推理
    i=i+1
#print(result)