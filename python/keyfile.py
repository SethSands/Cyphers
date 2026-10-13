def caesarkey(og):
    alpha="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
    result=""
    n=int(input("Enter shift distance: "))
    while n>62:
        n-=62
    for i in og:
        result+=alpha[alpha.index(i)-n]
    print(result)

def hexkey(og):
    wk=og.split(" ")
    _list=[]
    result=""
    for i in wk:
        if i=="":
            continue
        else:
            _list.append(chr(int(i,16)))
    for i in _list:
        result+=str(i)
    print(result)
    #pass

def chesskey(og):
    result=""
    ind=0
    rows=[1,2,3,4,5,6,7,8]
    columns=["A","B","C","D","E","F","G","H"]
    table=[]
    for col in columns:
        for row in rows:
            table.append(col+str(row))
    alpha="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789. "
    grid={table[i]:alpha[i] for i in range(len(alpha))}
    j=0
    while j<len(og):
        if j+1<len(og):
            pair=og[j:j+2]
            if pair in grid:
                result+=grid[pair]
                j+=2
    print(result)

def hcubekey(og):
    W=["A","B","C"]
    X=["Q","R","S"]
    Y=["x","y","z"]
    Z=["1","2","3"]
    table=[]
    result=""
    for i in W:
        for j in X:
            for k in Y:
                for l in Z:
                    table.append(i+j+k+l)
    alpha="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.,?!:'()[]{}-+*/=_ "
    grid={table[i]:alpha[i] for i in range(len(alpha))}
    j=0
    while j<len(og):
        if j+1<len(og):
            pair=og[j:j+4]
            if pair in grid:
                result+=grid[pair]
                j+=4
    print(result)

def octkey(og):
    octant_signs={
    1:(1,1,1),
    2:(1,-1,1),
    3:(-1,-1,1),
    4:(1,-1,1),
    5:(1,1,-1),
    6:(-1,1,-1),
    7:(-1,-1,-1),
    8:(1,-1,-1),}
    alpha="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.,?!:'()[]{}-+*/=_ "
    L=len(alpha)
    O=int(input("Choose octant (1–8): "))
    if O not in octant_signs:
        raise ValueError("Invalid octant")
    shifts=[]
    for i in range(3):
        shiftinput=int(input(f"Enter shift {i+1}:"))
        while shiftinput>90:
            shiftinput-=90
        shifts.append(shiftinput)
    sx,sy,sz=octant_signs[O]
    signed_shifts=[
        -1*shifts[0]*sx,
        -1*shifts[1]*sy,
        -1*shifts[2]*sz]
    shift_index=0
    result=""
    for ch in og:
        if ch in alpha:
            idx=alpha.index(ch)
            shift=signed_shifts[shift_index%3]
            result+=alpha[(idx+shift)]
            shift_index+=1
    print(result)
        
def decychoice(og):
    keys={"Rome":caesarkey,"b16":hexkey,"Gambit":chesskey,"tesseract":hcubekey,"3dsect":octkey}
    choice=input("Enter key: ").strip()
    if choice in keys:
        return keys[choice](og)
    else:
        print("Invalid.")
    

