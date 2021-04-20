function D = MPPT(V,v,I,i,d)

d = 0.58;
dv = V-v;
di = I -i;
if(dv==0)
    if(di==0)
        D=d;
    else
        if(di>0)
            D=d+0.05;
        else
            D=d-0.05;
        end
    end
end
if(di/dv == (I/V))
    D=d;
else
    if(di/dv >(I/V))
        D=d+0.05;
    else
        D=d-0.05;
    end
end

