# python3 
# Arturas Aleksandrauskas artal938 - TDDD95
import sys
def recover(pos, suff, recoverd):
    offset = 0
    for i in range(1, len(suff)+1):
        if suff[-i] != '*': 
            if recoverd[-i-offset] == ' ':            
                recoverd[-i-offset] = suff[-i]
            elif recoverd[-i-offset] != suff[-i]:
                return True
        else:
            offset = len(suff)- (pos - len(recoverd))
    return False


def main():
    tests = sys.stdin.readline()
    for _ in range(int(tests)):
        l, s = sys.stdin.readline().split()
        recoverd = [' ']*int(l)
        conflict = False
        for _ in range(int(s)):
            pos, suff = sys.stdin.readline().split()
            conflict = conflict or recover(int(pos)-1, suff, recoverd) # conflict if some sufix dont match
        if conflict or ' ' in recoverd: # if there are some waithespace left the reacinstucktion failed 
            print("IMPOSSIBLE")
        else:
            print("".join(recoverd))
				
if __name__ == "__main__":
    main()
