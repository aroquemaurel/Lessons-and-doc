/*1299570914,176832695*/

if (window.CavalryLogger) { CavalryLogger.start_js(["\/sTeh"]); }

function ads_refresh(k,g,f,h,l,j){if(window.ads_refreshing)return;if(l===undefined)l=0;if(j===undefined)j=0;var i=['sidebar_ads','home_sponsor_nile','ego'];var e=[];for(var d=0;d<i.length;d++)if(ge(i[d])||(i[d]=='ego'&&DOM.scry($('content'),'div.ego_column').length>0))e.push(i[d]);if(e.length===0)return;var c={page:g,queryId:j,tab:k,timestamp:(+new Date()),locations:e,photo_refresh:(h?'yes':'no'),cache:l};if(e.indexOf('ego')>=0)c.page_url=URI.getRequestURI().toString();var b=function(r){window.ads_refreshing=false;var m=r.getPayload();for(var q in m){if(q=='ego'){var n=DOM.scry($('content'),'div.ego_column');if(n.length>0){DOM.replace(n[0],HTML(m[q]));for(var p=1;p<n.length;++p)DOM.empty(n[p]);}continue;}var o=ge(q);if(o&&m[q].length>0)if(ua.ie()<7){o.outerHTML=m[q];}else DOM.replace(o,HTML(m[q]));}if(f)f(r);};var a=function(m){window.ads_refreshing=false;};new AsyncRequest().setURI('/ajax/location_refresh.php').setData(c).setOption('bundle',true).setHandler(b).setErrorHandler(a).send();window.ads_refreshing=true;}
var XD={_callbacks:[],_opts:{autoResize:false,allowShrink:true,channelUrl:null,hideOverflow:false,newResizeMethod:false,resizeTimeout:100,resizeWidth:false,expectResizeAck:false},init:function(a){this._opts=copy_properties(copy_properties({},this._opts),a);if(this._opts.autoResize)this._startResizeMonitor();Arbiter.subscribe('Connect.Unsafe.resize.ack',function(){this._opts.gotResizeAck=true;}.bind(this),Arbiter.BEHAVIOUR_PERSISTANT);},send:function(b,a){a=a||this._opts.channelUrl;if(!a)return;if(a.substr(0,4)!='http')return;var h=a+'&'+URI.implodeQuery(b),d='f'+(Math.random()*(1<<30)).toString(16).replace('.',''),c=document.body.appendChild(document.createElement('div')),g=false;c.style.position='absolute';c.style.top='-10000px';c.style.width='1px';c.style.height='1px';XD._callbacks[d]=function(){if(g){(function(){c.parentNode.removeChild(c);}).defer(3000);delete XD._callbacks[d];}};if(ua.ie()){var e=('<iframe '+' src="'+h+'"'+' onload="XD._callbacks.'+d+'()"'+'></iframe>');c.innerHTML='<iframe src="javascript:false"></iframe>';g=true;(function(){c.innerHTML=e;}).defer();}else{var f=document.createElement('iframe');f.onload=XD._callbacks[d];c.appendChild(f);g=true;f.src=h;}},_computeSize:function(){var a=document.body,e=document.documentElement,h=0,f;if(this._opts.newResizeMethod){f=Math.max(Math.max(a.offsetHeight,a.scrollHeight)+a.offsetTop,Math.max(e.offsetHeight,e.scrollHeight)+e.offsetTop);}else{if(ua.ie()){f=Math.max(a.offsetHeight,a.scrollHeight)+a.offsetTop;}else f=e.offsetHeight+e.offsetTop;if(window.Dialog)f=Math.max(f,Dialog.max_bottom);}if(this._opts.resizeWidth){if(a.offsetWidth<a.scrollWidth){h=a.scrollWidth+a.offsetLeft;}else{var d=a.childNodes;for(var g=0;g<d.length;g++){var b=d[g];var c=b.offsetWidth+b.offsetLeft;if(c>h)h=c;}}if(XD.forced_min_width)h=Math.max(h,XD.forced_min_width);if(e.clientLeft>0)h+=(e.clientLeft*2);if(e.clientTop>0)f+=(e.clientTop*2);}return {width:h,height:f};},_startResizeMonitor:function(){var b,a=document.documentElement;if(this._opts.hideOverflow){a.style.overflow='hidden';document.body.style.overflow='hidden';}(function(){var e=this._computeSize();if(!b||(this._opts.expectResizeAck&&!this._opts.gotResizeAck)||(this._opts.allowShrink&&b.width!=e.width)||(!this._opts.allowShrink&&b.width<e.width)||(this._opts.allowShrink&&b.height!=e.height)||(!this._opts.allowShrink&&b.height<e.height)){b=e;var d={type:'resize',height:e.height};if(e.width&&e.width!=0)d.width=e.width;try{if(URI(document.referrer).isFacebookURI()&&window.parent!=window&&window.name&&window.parent.location&&URI(window.parent.location).isFacebookURI()){var iframes=window.parent.document.getElementsByTagName('iframe');for(var i in iframes)if(iframes[i].name==window.name){if(this._opts.resizeWidth)iframes[i].style.width=d.width+'px';iframes[i].style.height=d.height+'px';}}this.send(d);}catch(c){this.send(d);}}}).bind(this).recur(this._opts.resizeTimeout);}};var UnverifiedXD=copy_properties({},XD);
var Base64=(function(){var c='ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/';function d(e){e=(e.charCodeAt(0)<<16)|(e.charCodeAt(1)<<8)|e.charCodeAt(2);return String.fromCharCode(c.charCodeAt(e>>>18),c.charCodeAt((e>>>12)&63),c.charCodeAt((e>>>6)&63),c.charCodeAt(e&63));}var a='>___?456789:;<=_______'+'\0\1\2\3\4\5\6\7\b\t\n\13\f\r\16\17\20\21\22\23\24\25\26\27\30\31'+'______\32\33\34\35\36\37 !"#$%&\'()*+,-./0123';function b(e){e=(a.charCodeAt(e.charCodeAt(0)-43)<<18)|(a.charCodeAt(e.charCodeAt(1)-43)<<12)|(a.charCodeAt(e.charCodeAt(2)-43)<<6)|a.charCodeAt(e.charCodeAt(3)-43);return String.fromCharCode(e>>>16,(e>>>8)&255,e&255);}return {encode:function(f){f=unescape(encodeURI(f));var e=(f.length+2)%3;f=(f+'\0\0'.slice(e)).replace(/[\s\S]{3}/g,d);return f.slice(0,f.length+e-2)+'=='.slice(e);},decode:function(g){g=g.replace(/[^A-Za-z0-9+\/]/g,'');var f=(g.length+3)&3,e;g=(g+'AAA'.slice(f)).replace(/..../g,b);g=g.slice(0,g.length+f-3);try{return decodeURIComponent(escape(g));}catch(e){throw new Error('Not valid UTF-8');}},encodeObject:function(e){return Base64.encode(JSON.stringify(e));},decodeObject:function(e){return JSON.parse(Base64.decode(e));},encodeNums:function(e){return String.fromCharCode.apply(String,e.map(function(f){return c.charCodeAt((f|-(f>63))&-(f>0)&63);}));}};})();
function ContextualDialog(b){var a=new Dialog();copy_properties(a,ContextualDialog.prototype);a._setFromModel(b);return a;}ContextualDialog.prototype={setContext:function(a){this._context=a;this._dirty();return this;},_buildDialogContent:function(){Bootloader.loadComponents('contextual-dialog-css',function(){CSS.addClass(this._obj,'contextual_dialog');this._content=this._frame=$N('div',{className:'contextual_dialog_content'});this._arrow=$N('div',{className:'arrow'});DOM.setContent(this._popup,[this._content,this._arrow]);}.bind(this));},_resetDialogObj:function(){if(!this._context)return;var a=Vector2.getElementPosition(this._context);var c=this._context.offsetWidth,b=this._context.offsetHeight;var d=a.x,e=a.y+b;if(c<64)d+=c/2-32;new Vector2(d,e,'document').setElementPosition(this._popup);},_renderDialog:function(a){if(window!=top)this._auto_focus=false;Dialog.prototype._renderDialog.call(this,a);}};
var PrivacyBaseValue={FACEBOOK_EMPLOYEES:112,CUSTOM:111,OPEN:100,EVERYONE:80,NETWORKS_FRIENDS_OF_FRIENDS:60,NETWORKS_FRIENDS:55,FRIENDS_OF_FRIENDS:50,ALL_FRIENDS:40,SELF:10,NOBODY:0};var PrivacyFriendsValue={EVERYONE:80,NETWORKS_FRIENDS:55,FRIENDS_OF_FRIENDS:50,ALL_FRIENDS:40,SOME_FRIENDS:30,SELF:10,NO_FRIENDS:0};var PrivacySpecialPreset={ONLY_CORP_NETWORK:200,COLLEGE_NETWORK_FRIENDS_OF_FRIENDS:201,COLLEGE_NETWORK_FRIENDS:202};var PrivacyNetworkTypes={TYPE_COLLEGE:1,TYPE_HS:2,TYPE_CORP:3,TYPE_GEO:4,TYPE_MANAGED:14,TYPE_TEST:50};var PrivacyNetworksAll=1;copy_properties(PrivacyBaseValue,PrivacySpecialPreset);function PrivacyModel(){this.value=PrivacyBaseValue.ALL_FRIENDS;this.friends=PrivacyFriendsValue.NO_FRIENDS;this.networks=[];this.objects=[];this.lists=[];this.lists_x=[];this.list_anon=0;this.ids_anon=[];this.list_x_anon=0;this.ids_x_anon=[];this.tdata={};return this;}copy_properties(PrivacyModel.prototype,{init:function(k,a,h,i,f,g,d,b,e,c,j){this.value=k;this.friends=a;this.networks=h.clone();this.objects=i.clone();this.lists=f.clone();this.lists_x=g.clone();this.list_anon=d;this.ids_anon=b.clone();this.list_x_anon=e;this.ids_x_anon=c.clone();j=j||{};copy_properties(this.tdata,j);},clone:function(){var a=new PrivacyModel();a.init(this.value,this.friends,this.networks,this.objects,this.lists,this.lists_x,this.list_anon,this.ids_anon,this.list_x_anon,this.ids_x_anon,this.tdata);return a;},getData:function(){var b=['value','friends','networks','objects','lists','lists_x','list_anon','ids_anon','list_x_anon','ids_x_anon'];var d={};for(var c=0;c<b.length;++c){var a=b[c];d[a]=this[a];}return d;}});
function BasePrivacyWidget(){}BasePrivacyWidget.mixin('Arbiter',{init:function(a,c,b){this._controllerId=a;this._root=$(a);this._options=copy_properties(b||{},c||{});this._formDataKey='privacy_data';},getData:function(){return this._model.getData();},_getPrivacyData:function(a){a=a||this._fbid;var b={};b[a]=this.getData();return b;},getRoot:function(){return this._root;},_initSelector:function(a){this._selector=a;Selector.listen(a,'select',function(b){var c=Selector.getOptionValue(b.option);this._onMenuSelect(c);}.bind(this));Event.listen(a,'click',function(){this.inform('menuActivated');}.bind(this));},_isCustomSetting:function(a){return (a==PrivacyBaseValue.CUSTOM);},_updateSelector:function(a){var b=this._model.objects;if(b&&b.length){selected_value=b[0];}else selected_value=this._model.value;Selector.setSelected(this._selector,selected_value);if(!this._isCustomSetting(selected_value))return;var c=Selector.getOption(this._selector,PrivacyBaseValue.CUSTOM+'');c.setAttribute('data-label',a||_tx("Personnaliser"));Selector.updateSelector(this._selector);},_onPrivacyChanged:function(){this._saveFormData();this.inform('privacyChanged',this.getData());Arbiter.inform(UIPrivacyWidget.GLOBAL_PRIVACY_CHANGED_EVENT,{fbid:this._fbid,data:this.getData()});},_saveFormData:function(){var b=DOM.find(this._root,'div.UIPrivacyWidget_Form');DOM.empty(b);var a={};if(this._options.useLegacyFormData){a[this._formDataKey]=this.getData();}else a[this._formDataKey]=this._getPrivacyData();Form.createHiddenInputs(a,b);}});
function UIPrivacyWidget(){this.parent.construct(this);}copy_properties(UIPrivacyWidget,{GLOBAL_PRIVACY_CHANGED_EVENT:'UIPrivacyWidget/globalPrivacyChanged',instances:{},getInstance:function(a){return this.instances[a];}});UIPrivacyWidget.extend('BasePrivacyWidget');UIPrivacyWidget.mixin('Arbiter',{init:function(i,a,b,h,c,e,g){var f={autoSave:false,saveAsDefaultFbid:0,initialExplanation:'',useLegacyFormData:false,composerEvents:false};if(b=='0')b=0;this.parent.init(a,g,f);this._lists=c;this._networks=e;this._fbid=b;this._row=h;this._groups={};for(var d in e)this._groups[e[d].fbid]=d;UIPrivacyWidget.instances[this._controllerId]=this;this._initSelector(i);this.setData(this._row,this._options.initialExplanation,true);this._saveFormData();if(this._options.composerEvents)Arbiter.subscribe('composer/publish',this.reset.bind(this));},reset:function(){this._model=this._originalModel.clone();this._modelClone=this._originalModel.clone();this._updateSelector(this._options.initialExplanation);this._saveFormData();return this;},revert:function(){this._model=this._modelClone.clone();this._updateSelector(this._previousDescription);this._saveFormData();return this;},getValue:function(){return this._model.value;},getDefaultValue:function(){return this._originalModel.value;},isEveryonePrivacy:function(){return this._model.value==PrivacyBaseValue.EVERYONE;},dialogOpen:function(){return this._dialog&&this._dialog.getRoot();},setData:function(b,a,c){this._model=new PrivacyModel();this._model.init(b.value,b.friends,b.networks,b.objects,b.lists,b.lists_x,b.list_anon,b.ids_anon,b.list_x_anon,b.ids_x_anon,b.tdata);this._modelClone=this._model.clone();if(c)this._originalModel=this._model.clone();this._previousDescription=a;this._customModel=null;this._updateSelector(a);},setLists:function(a){this._lists=a;return this;},setNetworks:function(a){this._networks=a;return this;},_isCustomSetting:function(a){return (a==PrivacyBaseValue.CUSTOM||a==PrivacyBaseValue.NETWORKS_FRIENDS_OF_FRIENDS||a==PrivacyBaseValue.SELF);},_onMenuSelect:function(b){this._modelClone=this._model.clone();var a=this._isCustomSetting(this._model.value);var c=this._isCustomSetting(b);if(a&&!c)this._customModel=this._model.clone();if(!(a&&c)){this._model.value=b;this._resetModelAuxiliaryData();}if(b==PrivacyBaseValue.CUSTOM){if(this._customModel){this._model=this._customModel.clone();}else if(this._modelClone.value!=PrivacyBaseValue.CUSTOM)this._model.friends=PrivacyFriendsValue.ALL_FRIENDS;this._showDialog();}else{if(this._groups[b]){this._model=new PrivacyModel();this._model.value=PrivacyBaseValue.CUSTOM;this._model.objects=[b];}this._onPrivacyChanged();if(this._options.autoSave)this._saveSetting();}this._updateSelector();},_showDialog:function(){if(!this._fbid){this._model.list_x_anon=0;this._model.list_anon=0;}var a={controller_id:this._controllerId,privacy_data:this.getData(),fbid:this._fbid,save_as_default_fbid:this._options.saveAsDefaultFbid};this._dialog=new Dialog().setAsync(new AsyncRequest('/ajax/privacy/privacy_widget_dialog.php').setData(a)).setModal(true).show();return false;},_resetModelAuxiliaryData:function(){if(this._model.value!=PrivacyBaseValue.CUSTOM){this._model.lists_x=this._model.lists=this._model.networks=this._model.ids_anon=this._model.ids_x_anon=[];this._model.list_x_anon=0;this._model.list_anon=0;}},_saveSetting:function(a){a=a||this._fbid;new AsyncRequest('/ajax/privacy/widget_save.php').setData({privacy_data:this._getPrivacyData(a),old_privacy_data:this._modelClone.getData(),fbid:a}).setHandler(this._handleResponse.bind(this)).setErrorHandler(this._handleError.bind(this)).send();},_handleResponse:function(b){var a=b.getPayload();this.setData(a.privacy_row,a.explanation);},_handleError:function(a){AsyncResponse.defaultErrorHandler(a);this.revert();}});

if (window.Bootloader) { Bootloader.done(["\/sTeh"]); }