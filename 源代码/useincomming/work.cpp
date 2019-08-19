#include "work.h"
#include<QDebug>

QString work_num(QString num)
{
    if (num.indexOf('.')!=-1)
    while (num.at(num.length()-1)=='0')
        num.remove(num.length()-1,1);
    if (num.at(num.length()-1)=='.')
        num.remove(num.length()-1,1);
    if (num.length()==2&&num.at(0)=='-'&&num.at(1)=='0')
        return "0";
    else
        return num;
}

QString work_str(QString s)
{
   int i=0,j=0;
   QString d="";
   QString* data=new QString[100];
   QString* data0=new QString[100];
   s.replace(QString("Mod"), QString("M"));
   int n=mid_pre(s,data);
   for (i=1;i<=n;i++)
       while (data[i].indexOf(' ')!=-1)
       {
           j++;
           data0[j]=data[i].mid(0,data[i].indexOf(' ')+1);
           data[i].remove(0,data[i].indexOf(' ')+1);
       }
   data=data0;
   n=j;
   data[0].setNum(n);
   data[n+1].setNum(1);
   data[n+2]="";
   data=work_mathML(data);
   d=data[n+2];
   delete[] data;

   d="<math>"+d+"</math>";

   return d;
}

int  mid_pre(QString s,QString* data)
{
    QString d[25];
    int i=0,j=0,n=0;
    while ((s.indexOf('+')+s.indexOf('-')>-2)&&(s.indexOf(' ')!=(s.length()-1)))
    {
        int x=0;
        do
        {
            i=s.indexOf('+',x);
            j=s.indexOf('-',x);
            if (((i>j)&&(j!=-1))||(i==-1)) i=j;
            if (s.at(i+1)!=" ")
            {
                x=i+1;
            }
        }while(s.at(i+1)!=" ");
        n++;
        d[n]=s.mid(0,i);
        s.remove(0,i);
        n++;
        d[n]=s.at(0);
        s.remove(0,2);
    }
    n++;
    d[n]=s;
    for (i=n;i>=1;i--)
        if ((d[i]=="+")||(d[i]=="-"))
        {
            data[(n-i+1)/2]=d[i]+" ";
        }else
        {
          //  qDebug()<<d[i]<<"lll";
            data[n-(n-i)/2]=mid_pre0(d[i]);
          //  qDebug()<<data[n-(n-i)/2]<<n-(n-i)/2;
        }
    return n;
}

QString mid_pre0(QString s)
{
    QString d="";
    int i=0,j=0,k=0;
    QString x="×";
    QString y="÷";
    i=s.indexOf(x);
    j=s.indexOf(y);
    k=s.indexOf("M");
    if ((i>j)&&(j!=-1)||(i==-1)) i=j;
    if ((i>k)&&(k!=-1)||(i==-1)) i=k;
    while (i>-1)
    {
        d=(QString)s.at(i)+" "+d;
        s.remove(i,2);
        i=s.indexOf(x);
        j=s.indexOf(y);
        k=s.indexOf("M");
        if ((i>j)&&(j!=-1)||(i==-1)) i=j;
        if ((i>k)&&(k!=-1)||(i==-1)) i=k;
    }
    while (s!="")
    {
        d+=mid_pre1(s.mid(0,s.indexOf(' ')));
        s.remove(0,s.indexOf(' ')+1);
    }
    return d;
}

QString mid_pre1(QString s)
{
    QString d="";
    while (s.at(s.length()-1)=='%')
    {
        d+="%";
        s.remove(s.length()-1,1);
    }
    while (s.at(s.length()-1)=='!')
    {
        d+="!";
        s.remove(s.length()-1,1);
    }
    while (s.indexOf('(')!=-1)
    {
  /*      bool ok=false,lj=false;
        if ((s.indexOf('√')>0)&&s.indexOf('(')>0) s.mid(s.indexOf('√')-1,1).toInt(&ok,10);
        if (ok) if (s.at(s.indexOf('(')-1)=='√') lj=true;
        if (lj)
        {
              d+=s.mid(0,s.indexOf('√'));
              s.remove(0,s.indexOf('√'));
              s.remove(s.lastIndexOf(')'),s.length()-s.lastIndexOf(')'));
        }
        else*/
        switch (s.indexOf('('))
        {
            case 0:
                bool tem;
                if (s.mid(s.lastIndexOf(')')+1,1)=="^")
                {
                    d+=s.mid(s.lastIndexOf(')')+1,s.length()-1)+"*";
                    s.remove(0,1);
                    s.remove(s.lastIndexOf(')'),s.length()-s.lastIndexOf(')'));
                }
           //     qDebug()<<s.mid(s.lastIndexOf(')')+1,1)<<s.at(s.lastIndexOf(')'));
                if (s.mid(s.lastIndexOf(')')+1,1)=="²")
                {

                    d+="²";
                    s.remove(0,1);
                    s.remove(s.length()-2,2);
                }
                if (s.mid(s.lastIndexOf(')')+1,1)=="³")
                {
                    d+="³";
                    s.remove(0,1);
                    s.remove(s.length()-2,2);
                }
                break;
            case 1:
                d+="√";
                s.remove(0,2);
                s.remove(s.length()-1,1);
                break;
            case 2:
                if (s.at(0)=='1')
                {
                    d+="/";
                    s.remove(0,3);
                    s.remove(s.length()-1,1);
                }
                else
                {
                    d=d+s.mid(0,s.indexOf('('))+"*";
                    s.remove(0,s.indexOf('(')+1);
                    s.remove(s.length()-1,1);
                }
                break;
            default:
                d=d+s.mid(0,s.indexOf('('))+"*";
                s.remove(0,s.indexOf('(')+1);
                s.remove(s.length()-1,1);
            break;
        }
        while (s.at(s.length()-1)=='%')
        {
            d+="%";
            s.remove(s.length()-1,1);
        }
        while (s.at(s.length()-1)=='!')
        {
            d+="!";
            s.remove(s.length()-1,1);
        }
    }
    d=d+s+" ";
    return d;
}

QString* work_mathML(QString* data)
{
    bool ok;
    int j=0,k=0;
    int n=data[0].toInt(&ok,10);
    int i=data[n+1].toInt(&ok,10);
    if (i>n) return NULL;
    qDebug()<<data[i];
    if (data[i].indexOf('.')==-1)
       j=data[i].toInt(&ok,10);
    else j=data[i].toDouble(&ok);
    if ((ok)||(data[i].mid(0,data[i].length()-1)=="π"))
    {
        if (data[i].mid(0,data[i].length()-1)=="π")
           { data[n+1].setNum(i+1);
            data[n+2]+="<pi/>";}
        else{
        data[n+1].setNum(i+1);
        data[n+2]+="<cn>"+data[i].mid(0,data[i].length()-1)+"</cn>";
        }return data;
    }
    else
    {       
        if (data[i]==(QString)"+ ")
        {
            data[n+2]+="<apply><plus/>";
            data[n+1].setNum(i+1);
            work_mathML(work_mathML(data));
            data[n+2]+="</apply>";
            return data;
        }
        if (data[i]==(QString)"- ")
        {
            data[n+2]+="<apply><minus/>";
            data[n+1].setNum(i+1);
            work_mathML(work_mathML(data));
            data[n+2]+="</apply>";
            return data;
        }
        if (data[i]==(QString)"× ")
        {
            data[n+2]+="<apply><times/>";
            data[n+1].setNum(i+1);
            work_mathML(work_mathML(data));
            data[n+2]+="</apply>";
            return data;
        }
        if (data[i]==(QString)"÷ ")
        {
            data[n+2]+="<apply><divide/>";
            data[n+1].setNum(i+1);
            work_mathML(work_mathML(data));
            data[n+2]+="</apply>";
            return data;
        }
        if (data[i]==(QString)"M ")
        {
            data[n+2]+="<apply><rem/>";
            data[n+1].setNum(i+1);
            work_mathML(work_mathML(data));
            data[n+2]+="</apply>";
            return data;
        }
        work_block(data);
        data[n+1].setNum(i+1);
        return data;
    }
}

void work_block(QString* data)
{
    bool ok;
    int n=data[0].toInt(&ok,10);
    int i=data[n+1].toInt(&ok,10);
//    qDebug()<<data[i];
    QString s=(QString)data[i].at(0);
    s.toInt(&ok,10);
    if (!ok)
    {
        if (s==(QString)"%")
        {
            data[i].remove(0,1);
            data[n+2]+="<apply><times/><cn>0.01</cn>";
            work_block(data);
            data[n+2]+="</apply>";
        }
        if (s==(QString)"!")
        {
            data[i].remove(0,1);
            data[n+2]+="<apply><factorial/>";
            work_block(data);
            data[n+2]+="</apply>";
        }
        if (s==(QString)"/")
        {
            data[i].remove(0,1);
            data[n+2]+="<apply><divide/><cn>1</cn>";
            work_block(data);
            data[n+2]+="</apply>";
        }
        if (s==(QString)"²")
        {
            data[i].remove(0,1);
            data[n+2]+="<apply><power/>";
            work_block(data);
            data[n+2]+="<cn>2</cn></apply>";
        }
        if (s==(QString)"³")
        {
            data[i].remove(0,1);
            data[n+2]+="<apply><power/>";
            work_block(data);
            data[n+2]+="<cn>3</cn></apply>";
        }
        if (s==(QString)"√")
        {
            data[i].remove(0,1);
            data[n+2]+="<apply><root/>";
            work_block(data);
            data[n+2]+="</apply>";
        }
        if (s==(QString)"^")
        {
            data[i].remove(0,1);
            int tem=-1;
            QString tems="";
            do
            {
                tem++;
                s=(QString)data[i].at(tem);
                s.toInt(&ok,10);
            }while (s!='*');
            tems=data[i].mid(0,tem);
            data[i].remove(0,tem+1);
            data[n+2]+="<apply><power/>";
            work_block(data);
            data[n+2]+="<cn>"+tems+"</cn></apply>";
        }
        if (s==(QString)"π")
        {
            data[i].remove(0,1);
            data[n+2]+="<pi/>";
            if (data[i]!="") work_block(data);
        }
        QString tem="";
        while((!ok)&&(s!="*")&&(data[i]!=" "))
        {
            tem+=s;
            data[i].remove(0,1);
            s=(QString)data[i].at(0);
            s.toInt(&ok,10);
        }
        if (s=="*") data[i].remove(0,1);
        if (tem!="")
        {
            if (tem=="e")
            {
                data[n+2]+="<cn>2.718281828</cn>";
                work_block(data);
            }else
            {
                if (tem=="sin⁻¹") tem.remove(3,1);
                if (tem=="cos⁻¹") tem.remove(3,1);
                if (tem=="tan⁻¹") tem.remove(3,1);
                if (tem=="sinh⁻¹") tem.remove(4,1);
                if (tem=="cosh⁻¹") tem.remove(4,1);
                if (tem=="tanh⁻¹") tem.remove(4,1);
                data[n+2]+="<apply><"+tem+"/>";
                work_block(data);
                data[n+2]+="</apply>";
            }
        }
    }
    else
    {
        if (data[i]!=" ")
        data[n+2]+="<cn>"+data[i].mid(0,data[i].length()-1)+"</cn>";
        data[i]=" ";
    }
}
