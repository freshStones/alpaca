#include "qunarpolicyapi.h"

QunarPolicyAPI::QunarPolicyAPI()
{
}

QString QunarPolicyAPI::domToFile(QDomDocument doc)
{
    QString xmlfile = "test.xml";
    QFile file(xmlfile);
    if (!file.open(QFile::WriteOnly | QFile::Text))
        return xmlfile;
    QTextStream out(&file);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    out.setCodec(codec);
    out<<doc.toString();
    file.close();
    return xmlfile;
}

QString QunarPolicyAPI::toZip(QString filename)
{

}

QDomDocument QunarPolicyAPI::uploadPolicy()
{
    QDomDocument doc;
    QDomProcessingInstruction instruction = doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
    QDomElement policyList = doc.createElement("PolicyList");
    doc.appendChild(instruction);
    doc.appendChild(policyList);

    policyList.setAttribute("username","lh");
    policyList.setAttribute("password","");
    policyList.setAttribute("ext","");
    policyList.setAttribute("execType","");
    policyList.setAttribute("type","");

    QDomElement deletePolicy = doc.createElement("DeletePolicy");
    policyList.appendChild(deletePolicy);

    deletePolicy.setAttribute("type","");
    deletePolicy.setAttribute("flightcode","");
    deletePolicy.setAttribute("policyCode","");
    deletePolicy.setAttribute("dpt","");
    deletePolicy.setAttribute("arr","");
    deletePolicy.setAttribute("carbin","");
    deletePolicy.setAttribute("startdate","");
    deletePolicy.setAttribute("enddate","");

    QDomElement policy = doc.createElement("Policy");
    policyList.appendChild(policy);

    policy.setAttribute("flightcode","");
    policy.setAttribute("policyCode","");
    policy.setAttribute("dpt","");
    policy.setAttribute("arr","");
    policy.setAttribute("flightNumLimit","");
    policy.setAttribute("flightcondition","");
    policy.setAttribute("daycondition","");
    policy.setAttribute("carbin","");
    policy.setAttribute("discountType","");
    policy.setAttribute("discountValue","");
    policy.setAttribute("returnpoint","");
    policy.setAttribute("returnprice","");
    policy.setAttribute("startdate_ticket","");
    policy.setAttribute("enfdate_ticket","");
    policy.setAttribute("startdate","");
    policy.setAttribute("enddate","");
    policy.setAttribute("beforeValidDay","");
    policy.setAttribute("backnote","");
    policy.setAttribute("carbinnote","");
    policy.setAttribute("autoTicket","");
    policy.setAttribute("shared","");
    policy.setAttribute("officeno","");
    policy.setAttribute("xcd","");
    policy.setAttribute("flyerpoints","");
    policy.setAttribute("cardType","");
    policy.setAttribute("maxAge","");
    policy.setAttribute("minAge","");

    return doc;
}
