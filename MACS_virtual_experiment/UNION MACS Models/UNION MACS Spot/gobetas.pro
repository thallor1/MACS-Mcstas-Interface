pro plotbetas,dmbt

;DATA FOR DMBT=20
tt    =  [43.,50.,60.,70.,80.,90.,100.,110.,120.]

if dmbt eq 20 then begin
  title='DMBT=20'
  beta1 =  [0.3,0.45,0.7,0.87,0.87,1.10,1.14,1.20,1.28]
  beta2=  [1.66,2.08,2.12,2.20,2.23,2.19,2.17,2.07,2.00]
endif

;data for dmbt=10
if dmbt eq 10 then begin
    title='DMBT=10'
    beta1 = [0.4, 0.63, 0.8, 0.95, 1.22, 1.29, 1.45, 1.57, 1.58]
    beta2 = [2.07, 2.02, 2.13, 2.18, 2.32, 2.30, 2.21, 2.07, 2.05]
endif


;data for dmbt 5
if dmbt eq 5 then begin
    title='DMBT=5'
    beta1 =[0.7, 1.19, 1.32, 1.30, 1.40, 1.57, 1.70, 1.71, 2.0]
    beta2 = [2.28, 2.55, 2.49, 2.69, 2.52, 2.43, 2.44, 2.21, 2.21]
endif


;data for dmbt=15
if dmbt eq 15 then begin
    title='DMBT=15'
    beta1=[0.43, 0.41, 0.58, 0.77, 0.95, 1.13, 1.21, 1.43, 1.35]
    beta2=[2.09, 2.12, 2.22, 2.31, 2.28, 2.17, 2.14, 2.11, 2.02]
endif

;data for dmbt=25
if dmbt eq 25 then begin
    title='DMBT=25'
    beta1=[0.1, 0.16, 0.23, 0.58, 0.68, 0.92, 1.08, 1.10, 1.16]
    beta2=[1.68, 2.14, 2.20, 2.39, 2.23, 2.16, 2.17, 2.01, 1.98]
endif



dbeta1   = [0.05, 0.03, 0.03, 0.02 ,0.04, 0.03, 0.05, 0.03, 0.04]
dbeta2   = [0.02, 0.01, 0.01, 0.03, 0.03, 0.02, 0.03, 0.02, 0.02]

errplot,tt,beta1-dbeta1,beta1+dbeta1
errplot,tt,beta2-dbeta2,beta2+dbeta2


ttc   =  min(tt)+findgen(200)/199*(max(tt)-min(tt))

pbeta1=poly_fit(tt,beta1,5,MEASURE_ERRORS=dbeta1)
pbeta2=poly_fit(tt,beta2,5,MEASURE_ERRORS=dbeta2)
          

device,decomposed=0
loadct,1 
circle  
plot,tt,beta1,psym=8,title=title,xtit='2 Theta',ytit='beta1 and beta2',yr=[0,3],xr=[30,130],charsize=2,color=0,background=255
bullet
oplot,tt,beta2,psym=8,color=100
dbeta1   = [0.05, 0.03, 0.03, 0.02 ,0.04, 0.03, 0.05, 0.03, 0.04]
dbeta2   = [0.02, 0.01, 0.01, 0.03, 0.03, 0.02, 0.03, 0.02, 0.02]

errplot,tt,beta1-dbeta1,beta1+dbeta1,color=0
errplot,tt,beta2-dbeta2,beta2+dbeta2,color=100

polynomial,ttc,pbeta1,beta1c
polynomial,ttc,pbeta2,beta2c
oplot,ttc,beta1c,color=0
oplot,ttc,beta2c,color=100

end


pro plot_all_betas,jpg=jpg

    window,/free,xsize=1000,ysize=1000
    !p.multi=[0,2,3,0,0]
    dmbt=[5,10,15,20,25]
    for nn=0,n_elements(dmbt)-1 do begin
        plotbetas,dmbt[nn]
    endfor

    if keyword_set(jpg) then begin
         filename= 'C:\Users\joarodri\Documents\MACS\MACS\Mirrors optimization 20130220\all_betas.jpg'
         WRITE_JPEG, filename, TVRD(/TRUE), /TRUE
         PRINT, 'File written to ', filename
    endif
!p.multi=0
end



pro plotbetas_tt,tt
tt_all    =  [43.,50.,60.,70.,80.,90.,100.,110.,120.]
dmbt_all=[5,10,15,20,25.]
beta1_20 =  [0.3,0.45,0.7,0.87,0.87,1.10,1.14,1.20,1.28]
beta2_20 =  [1.66,2.08,2.12,2.20,2.23,2.19,2.17,2.07,2.00]
beta1_10 = [0.4, 0.63, 0.8, 0.95, 1.22, 1.29, 1.45, 1.57, 1.58]
beta2_10 = [2.07, 2.02, 2.13, 2.18, 2.32, 2.30, 2.21, 2.07, 2.05]
beta1_5 =[0.7, 1.19, 1.32, 1.30, 1.40, 1.57, 1.70, 1.71, 2.0]
beta2_5 = [2.28, 2.55, 2.49, 2.69, 2.52, 2.43, 2.44, 2.21, 2.21]
beta1_15=[0.43, 0.41, 0.58, 0.77, 0.95, 1.13, 1.21, 1.43, 1.35]
beta2_15=[2.09, 2.12, 2.22, 2.31, 2.28, 2.17, 2.14, 2.11, 2.02]
beta1_25=[0.1, 0.16, 0.23, 0.58, 0.68, 0.92, 1.08, 1.10, 1.16]
beta2_25=[1.68, 2.14, 2.20, 2.39, 2.23, 2.16, 2.17, 2.01, 1.98]

all_betas1=[ [beta1_5], [beta1_10], [beta1_15],[beta1_20], [beta1_25]]
all_betas2=[ [beta2_5], [beta2_10], [beta2_15],[beta2_20], [beta2_25]]

aa=where(tt eq tt_all)
print,aa

device,decomposed=0
loadct,1 
circle 
Title= 'DMBT '+num2string(tt)
 
plot,dmbt_all,all_betas1[aa,*],psym=8,title=title,xtit='DMBT',ytit='beta1 and beta2',yr=[0,3],xr=[0,30],charsize=2,color=0,background=255
bullet
oplot,dmbt_all,all_betas2[aa,*],psym=8,color=200

pbeta1=poly_fit(dmbt_all,all_betas1[aa,*],3,MEASURE_ERRORS=dbeta1)
pbeta2=poly_fit(dmbt_all,all_betas2[aa,*],3,MEASURE_ERRORS=dbeta2)
dmbtc =  5.+findgen(200)/199*(25.- 5.)        
polynomial,dmbtc,pbeta1,beta1c
polynomial,dmbtc,pbeta2,beta2c
oplot,dmbtc,beta1c,color=0
oplot,dmbtc,beta2c,color=100


end

pro plot_all_betas_tt,jpg=jpg
 
    window,/free,xsize=1200,ysize=800
    !p.multi=[0,3,3,0,0]
    tt_all    =  [43.,50.,60.,70.,80.,90.,100.,110.,120.]
    for nn=0,n_elements(tt_all)-1 do begin
        plotbetas_tt,tt_all[nn]
    endfor

    if keyword_set(jpg) then begin
         filename= 'C:\Users\joarodri\Documents\MACS\MACS\Mirrors optimization 20130220\all_betas_dmbt.jpg'
         WRITE_JPEG, filename, TVRD(/TRUE), /TRUE
         PRINT, 'File written to ', filename
    endif
!p.multi=0
end




function betas,tt,dmbt
    tt_all    =  [43.,50.,60.,70.,80.,90.,100.,110.,120.]
    dmbt_all=[5,10,15,20,25.]  
    ttc_mat_b1 = fltarr(n_elements(dmbt_all))
    ttc_mat_b2 = fltarr(n_elements(dmbt_all))  
    beta1_20 =  [0.3,0.45,0.7,0.87,0.87,1.10,1.14,1.20,1.28]
    beta2_20 =  [1.66,2.08,2.12,2.20,2.23,2.19,2.17,2.07,2.00]
    beta1_10 = [0.4, 0.63, 0.8, 0.95, 1.22, 1.29, 1.45, 1.57, 1.58]
    beta2_10 = [2.07, 2.02, 2.13, 2.18, 2.32, 2.30, 2.21, 2.07, 2.05]
    beta1_5 =[0.7, 1.19, 1.32, 1.30, 1.40, 1.57, 1.70, 1.71, 2.0]
    beta2_5 = [2.28, 2.55, 2.49, 2.69, 2.52, 2.43, 2.44, 2.21, 2.21]
    beta1_15=[0.43, 0.41, 0.58, 0.77, 0.95, 1.13, 1.21, 1.43, 1.35]
    beta2_15=[2.09, 2.12, 2.22, 2.31, 2.28, 2.17, 2.14, 2.11, 2.02]
    beta1_25=[0.1, 0.16, 0.23, 0.58, 0.68, 0.92, 1.08, 1.10, 1.16]
    beta2_25=[1.68, 2.14, 2.20, 2.39, 2.23, 2.16, 2.17, 2.01, 1.98]
    dbeta1   = [0.05, 0.03, 0.03, 0.02 ,0.04, 0.03, 0.05, 0.03, 0.04]
    dbeta2   = [0.02, 0.01, 0.01, 0.03, 0.03, 0.02, 0.03, 0.02, 0.02]   
    all_betas1=[ [beta1_5], [beta1_10], [beta1_15],[beta1_20], [beta1_25]]
    all_betas2=[ [beta2_5], [beta2_10], [beta2_15],[beta2_20], [beta2_25]]
    for nn=0,4 do begin
      pbeta1=poly_fit(tt_all,all_betas1[*,nn],5,MEASURE_ERRORS=dbeta1)
      pbeta2=poly_fit(tt_all,all_betas2[*,nn],5,MEASURE_ERRORS=dbeta2)
      polynomial,tt,pbeta1,xx
      ttc_mat_b1[nn]=xx
      polynomial,tt,pbeta2,xx
      ttc_mat_b2[nn]=xx 
    endfor     
    pbeta1=poly_fit(dmbt_all,ttc_mat_b1,3)
    pbeta2=poly_fit(dmbt_all,ttc_mat_b2,3)
    polynomial,dmbt,pbeta1,beta1c
    polynomial,dmbt,pbeta2,beta2c 
   return,[beta1c,beta2c]
end


function betas_ei,ei,dmbt
taum  =  1.87325
ki =  sqrt(ei/2.072)
ttc =  2*asin(taum/2./ki)/!dtor
beta12 = betas(ttc,dmbt)
return, beta12
end



pro gobetas,ei,dmbt
taum  =  1.87325
ki =  sqrt(ei/2.072)
ttc =  2*asin(taum/2./ki)/!dtor
beta12 = betas(ttc,dmbt)
com2send='move beta1 '+num2string(beta12[0])+' beta2 '+num2string(beta12[1])
sendcom,com2send
end


pro printbetas
ei=[13.5,13.0,12.5,12.0,11.5,11.0,10.5,10.0,9.5,9.0,8.5,8.0]
for nn=0,n_elements(ei)-1 do begin
  gobetas=betas_ei(ei[nn],20.)
  print, 'move ei ', ei[nn], ' beta1 ',gobetas[0],' beta2 ',gobetas[1]
  print,'wait 99999999'
  print, 'ct/t 30'
  print,'wait 99999999'
  print, 'ct/t 30'
endfor

end


pro plot2d_betas,beta_plot
    tt_all    =  [43.,50.,60.,70.,80.,90.,100.,110.,120.]
    dmbt_all=[5,10,15,20,25.]
    beta1_20 =  [0.3,0.45,0.7,0.87,0.87,1.10,1.14,1.20,1.28]
    beta2_20 =  [1.66,2.08,2.12,2.20,2.23,2.19,2.17,2.07,2.00]
    beta1_10 = [0.4, 0.63, 0.8, 0.95, 1.22, 1.29, 1.45, 1.57, 1.58]
    beta2_10 = [2.07, 2.02, 2.13, 2.18, 2.32, 2.30, 2.21, 2.07, 2.05]
    beta1_5 =[0.7, 1.19, 1.32, 1.30, 1.40, 1.57, 1.70, 1.71, 2.0]
    beta2_5 = [2.28, 2.55, 2.49, 2.69, 2.52, 2.43, 2.44, 2.21, 2.21]
    beta1_15=[0.43, 0.41, 0.58, 0.77, 0.95, 1.13, 1.21, 1.43, 1.35]
    beta2_15=[2.09, 2.12, 2.22, 2.31, 2.28, 2.17, 2.14, 2.11, 2.02]
    beta1_25=[0.1, 0.16, 0.23, 0.58, 0.68, 0.92, 1.08, 1.10, 1.16]
    beta2_25=[1.68, 2.14, 2.20, 2.39, 2.23, 2.16, 2.17, 2.01, 1.98]
    

    all_betas1 = [ beta1_5, beta1_10, beta1_15, beta1_20,  beta1_25 ]
    all_betas2=[ beta2_5, beta2_10, beta2_15, beta2_20, beta2_25]
    twotheta = [tt_all, tt_all, tt_all, tt_all,tt_all]
    dmbt=[5.,5,5,5,5,5,5,5,5,10,10,10,10,10,10,10,10,10,15,15,15,15,15,15,15,15,15,20,20,20,20,20,20,20,20,20,25,25,25,25,25,25,25,25,25]
    beta1_err=all_betas1*0.01
    beta2_err=all_betas2*0.01
    
    data=[[all_betas1],[beta1_err],[twotheta],[dmbt]]
    if beta_plot eq 2 then data=[[all_betas2],[beta2_err],[twotheta],[dmbt]]
 ;    PI_str = '!9' + String("160B) + '!X'
 ;    omega_str='!9' + String("167B) + '!X'
     
      label  = ['Beta1','Errorbeta','Twotheta','dmbt']
         unit   = ['','','','']
          instrument = 'MACS-1'
          dataPtr = ptr_new({data:data,label:label,unit:unit,instrument:instrument})
          obj_mslice = obj_new('dcs_mslice',dataPtr=dataPtr)

end


pro plot2d_betas_calc,beta_plot
dmbtc =  5.+findgen(100)/99*(25.- 5.)
ttc =  43.+findgen(100)/99*(120.- 43.)
ttc_nn = fltarr(n_elements(ttc)*n_elements(dmbtc))
dmbtc_nn = fltarr(n_elements(ttc)*n_elements(dmbtc))
beta1=fltarr(n_elements(ttc)*n_elements(dmbtc))
beta2=fltarr(n_elements(ttc)*n_elements(dmbtc))

n_cnt=0
for nn=00,n_elements(ttc)-1 do begin
    for mm=0, n_elements(dmbtc)-1 do begin
    allbetas= betas(ttc[nn],dmbtc[mm])
    ttc_nn[n_cnt]=ttc[nn]
    dmbtc_nn[n_cnt]=dmbtc[mm]
    beta1[n_cnt]=allbetas[0]
    beta2[n_cnt]=allbetas[1]
    n_cnt=n_cnt+1
    endfor
endfor
beta1_err=beta1*0.01
beta2_err=beta2*0.01

    data=[[beta1],[beta1_err],[ttc_nn],[dmbtc_nn]]
    if beta_plot eq 2 then data=[[beta2],[beta2_err],[ttc_nn],[dmbtc_nn]]
     
      label  = ['Beta1','Errorbeta','Twotheta','dmbt']
         unit   = ['','','','']
          instrument = 'MACS-1'
          dataPtr = ptr_new({data:data,label:label,unit:unit,instrument:instrument})
          obj_mslice = obj_new('dcs_mslice',dataPtr=dataPtr)

end
