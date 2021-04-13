def alter(file):
    """
    替换文件中的字符
    """
    file_data = ""
    with open(file, "r", encoding="utf-8") as f:
        for line in f:
            if 'dissect_per_enumerated(tvb, offset,' in line:
                line = line.replace("NULL);","NULL, 1);")
            file_data += line
    with open(file,"w",encoding="utf-8") as f:
        f.write(file_data)

alter("s1.c")