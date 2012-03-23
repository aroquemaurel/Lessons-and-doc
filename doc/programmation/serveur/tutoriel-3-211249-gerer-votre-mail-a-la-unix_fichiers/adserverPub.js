
function smartadserver()
{
    sas_tmstp=Math.round(Math.random()*10000000000);sas_masterflag=1;
    function SmartAdServer(sas_pageid,sas_formatid,sas_target) {
     if (sas_masterflag==1) {sas_masterflag=0;sas_master='M';} else
    {sas_master='S';};
     document.write('<scr'+'ipt src="http://www.smartadserver.com/call/pubj/' + sas_pageid + '/' +
    sas_formatid + '/' + sas_master + '/' + sas_tmstp + '/' +
    escape(sas_target) + '?"></scr'+'ipt>');
    }
    sas_pageid='22332/152674'; // Page : SdZ/tout
    sas_formatid=1825; // Format : 300X250 300x250
    sas_target=''; // Targeting
    SmartAdServer(sas_pageid,sas_formatid,sas_target);

    $('#pave_pub_tuto').show();
}

function evolia()
{
    var rdads=new String(Math.random()).substring (2, 11);
    document.write('<sc'+'ript type="text/javascript" src="http://server1.evonia.fr/tracking/ads_display.php?n=32325f35385f323439_736f4de2a0&rdads='+rdads+'"></sc'+'ript>');
    $('#pave_pub_tuto').show();
}