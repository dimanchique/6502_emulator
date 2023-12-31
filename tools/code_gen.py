import os

script_path = __file__
parent = os.path.split(__file__)[0]
root = os.path.split(parent)[0]
read_target = os.path.join(os.path.join(root, 'inc'), 'MOS6502_OpCodes.h')
write_target = os.path.join(os.path.join(root, 'inc'), 'MOS6502_OpCodesList.h')

with open(read_target, 'r') as file:
    data = file.readlines()

data = [i for i in data if '=' in i]

op_map = dict()
for i in data:
    splitter = i.split('=')
    key = splitter[0].strip()
    value = int(splitter[1][1:].split(',')[0], 16)
    op_map[key] = value

ops = ['ADD_CALL(FAKE_NOP)'] * 255

used_instructions = 0
for i in op_map:
    ops[op_map[i]] = f'ADD_CALL({i})'
    used_instructions += 1

print(f"Used instructions: {used_instructions}/{len(op_map.keys())}")

ops_strings = []
while ops:
    line = ops[:5]
    ops = ops[5:]
    line_str = []
    for i in line:
        line_str.append((str(i) + ',').ljust(20))
    res = ''.join(line_str)
    ops_strings.append(res)

ops_strings = '\n'.join(ops_strings)

with open(write_target, 'w') as file:
    file.writelines(ops_strings)
