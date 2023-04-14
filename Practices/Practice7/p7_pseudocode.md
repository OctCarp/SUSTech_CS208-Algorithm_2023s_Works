```
Function check (n, x_origin, y_origin):
    IF n=0
    	RETURN 1
    ELSE
        base ← 2^(n-1)
        xd = x_origin-base, yd = y_origin-base

        CASE xd, yd OF:
            xd<=0, yd<=0:
                blocks ← 0
                x_next = y_origin, y_next = x_origin
            xd<=0, yd>0:
                blocks ← 1
                x_next = x_origin, y_next = yd
            xd>0, yd>0:
                blocks ← 2
                x_next = xd, y_next = yd
            xd>0, yd<=0:
                blocks ← 3
                x_next = base+1-y_origion, y_next = base+1-xd
        ENDCASE
        
        RETURN blocks × base^2 + CALL check with (n-1, x_next, y_next)
    ENDIF

END Function

INPUT n,x,y
OUTPUT check(n,x,y)
```