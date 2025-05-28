target = 4
items = [1, 2]

# 🔷 组合数（先物品后背包）：顺序不重要
comb_paths = [[] for _ in range(target + 1)]
comb_paths[0] = [[]]  # 初始化：组成 0 有一种方式：空列表

for i in items:
    for j in range(i, target + 1):
        for path in comb_paths[j - i]:
            comb_paths[j].append(path + [i])

# 🔷 排列数（先背包后物品）：顺序重要
perm_paths = [[] for _ in range(target + 1)]
perm_paths[0] = [[]]

for j in range(1, target + 1):
    for i in items:
        if j >= i:
            for path in perm_paths[j - i]:
                perm_paths[j].append(path + [i])

# 🔍 打印
print("【组合】方式数：", len(comb_paths[target]))
for p in comb_paths[target]:
    print("组合：", p)

print("\n【排列】方式数：", len(perm_paths[target]))
for p in perm_paths[target]:
    print("排列：", p)
