#ifndef WORK_H
#define WORK_H
#include <QtXml\QtXml>
#include <QtXml\QDomDocument>
#include "work.h"
#include<QDebug>
#include<math.h>
template<typename T> T work_c(QDomElement doc)
{
    QDomElement n = doc.firstChildElement();
    bool num;
    QString tagN=n.tagName();
    qDebug()<<tagN;
    if (tagN=="")
    {      
        if (doc.nodeName()=="pi")
            return 3.1415926535;
        else
            return (T)doc.text().toDouble();
    }
    QDomElement n1=n.nextSiblingElement();
    if (tagN=="factorial")
    {
        int i,ans=1;
        for (i=1;i<=work_c<long long>(n1);i++)
        {
            ans*=i;
        }
        return ans;
    }
    if (tagN=="root")
    {
        return (T)sqrt(work_c<T>(n1));
    }
    if (tagN=="log")
    {
        return (T)log10(work_c<T>(n1));
    }
    if (tagN=="ln")
    {
        return (T)log(work_c<T>(n1));
    }
    if (tagN=="sin")
    {
        return (T)sin(work_c<T>(n1));
    }
    if (tagN=="sin₉")
    {
        return (T)sin(work_c<T>(n1)/200*3.1415926535);
    }
    if (tagN=="sin₀")
    {
        return (T)sin(work_c<T>(n1)/180*3.1415926535);
    }
    if (tagN=="sin¹")
    {
 //       qDebug()<<work_c<T>(n1)<<asin(work_c<T>(n1));
        return (T)asin(work_c<T>(n1));
    }
    if (tagN=="sin¹₉")
    {
        return (T)asin(work_c<T>(n1)/200*3.1415926535);
    }
    if (tagN=="sin¹₀")
    {
        return (T)asin(work_c<T>(n1)/180*3.1415926535);
    }
    if (tagN=="sinh")
    {
        return (T)sinh(work_c<T>(n1));
    }
    if (tagN=="cos")
    {
        return (T)cos(work_c<T>(n1));
    }
    if (tagN=="cos₉")
    {
        return (T)cos(work_c<T>(n1)/200*3.1415926535);
    }
    if (tagN=="cos₀")
    {
        return (T)cos(work_c<T>(n1)/180*3.1415926535);
    }
    if (tagN=="cos¹")
    {
        //qDebug()<<work_c<T>(n1)<<asin(work_c<T>(n1));
        return (T)acos(work_c<T>(n1));
    }
    if (tagN=="cos¹₉")
    {
        return (T)acos(work_c<T>(n1)/200*3.1415926535);
    }
    if (tagN=="cos¹₀")
    {
        return (T)acos(work_c<T>(n1)/180*3.1415926535);
    }
    if (tagN=="cosh")
    {
        return (T)cosh(work_c<T>(n1));
    }
    if (tagN=="tan")
    {
        return (T)tan(work_c<T>(n1));
    }
    if (tagN=="tan₉")
    {
        return (T)tan(work_c<T>(n1)/200*3.1415926535);
    }
    if (tagN=="tan₀")
    {
        return (T)tan(work_c<T>(n1)/180*3.1415926535);
    }
    if (tagN=="tan¹")
    {
   //     qDebug()<<work_c<T>(n1)<<asin(work_c<T>(n1));
        return (T)atan(work_c<T>(n1));
    }
    if (tagN=="tan¹₉")
    {
        return (T)atan(work_c<T>(n1)/200*3.1415926535);
    }
    if (tagN=="tan¹₀")
    {
        return (T)atan(work_c<T>(n1)/180*3.1415926535);
    }
    if (tagN=="tanh")
    {
        return (T)tanh(work_c<T>(n1));
    }
    QDomElement n2=n1.nextSiblingElement();
    if (tagN=="power")
    {
       return powl(work_c<T>(n1),work_c<T>(n2));
    }
    if (tagN=="plus")
    {
        return (T)work_c<T>(n1)+work_c<T>(n2);
    }
    if (tagN=="minus")
    {
        return (T)work_c<T>(n1)-work_c<T>(n2);
    }
    if (tagN=="times")
    {
        return (T)work_c<T>(n1)*work_c<T>(n2);
    }
    if (tagN=="divide")
    {
  //      qDebug()<<(T)work_c<T>(n1)/work_c<T>(n2);
        return (T)work_c<T>(n1)/(T)work_c<T>(n2);
    }
    if (tagN=="rem")
    {
  //      qDebug()<<(long long)work_c<long long>(n1) % work_c<long long>(n2);
        return (long long)work_c<long long>(n1) % (long long )work_c<long long>(n2);
    }
}

template<typename T> T work(QString mMLs)
{
    T ans;
    QDomDocument doc;
    doc.setContent(mMLs);
    QDomElement docElem = doc.documentElement(); //返回根元素
    docElem=docElem.firstChildElement();
    ans = work_c<T>(docElem);
    return ans;
}

#endif // WORK_H
