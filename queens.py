def tryrows(size, column, bad):
  for i in range(size):
    bad_row = False
    # udadd means up-diagonal, across, down-diagonal
    # udadd = (0,0,0)
    for udadd in bad:
      if i in udadd:
        bad_row = True
        break 
    if bad_row:
      continue
    if column == size - 1:
      return "%s-%s" % (column, i)
    res = tryrows(size,
        column+1, [(i-1, i, i+1)] + [(a-1, b, c+1) for a, b, c in bad])
    if res:
      return "%s-%s " % (column, i) + res
  return ""
print (tryrows(8, 0, []))
