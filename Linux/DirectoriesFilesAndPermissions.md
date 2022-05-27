# Directories, files and permissions
## File type
- `d` = directory
- `-` = file
- `l` = link

## Permissions
Common example:
```
| OWNER | GROUP | WORLD |
| r w x | r w x | r w x |
| 4 2 1 | 4 2 1 | 4 2 1 |
| 1 1 1 | 1 0 0 | 1 0 0 |
|_______|_______|_______|
    7       4       4
    \_______|_______/
            |
           744
```

All combinations:
```
| r w x | r w - | r - x | r - - | - w x | - w - | - - x | - - - |
| 4 2 1 | 4 2 1 | 4 2 1 | 4 2 1 | 4 2 1 | 4 2 1 | 4 2 1 | 4 2 1 |
| 1 1 1 | 1 1 0 | 1 0 1 | 1 0 0 | 0 1 1 | 0 1 0 | 0 0 1 | 0 0 0 |
|_______|_______|_______|_______|_______|_______|_______|_______|
    7       6       5       4       3       2       1       0
```

## Link count
