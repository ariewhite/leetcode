import os

path = r"/Users/murzabaev/Projects/leetcode"

def rename_dir(path):
    
    for x in os.listdir(path):
        print(x)
        
    
    
rename_dir(path)