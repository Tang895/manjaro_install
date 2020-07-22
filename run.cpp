#include<iostream>
#include<cstring>
using namespace std;
void tringhua(){
    system("echo 'Server = https://mirrors.tuna.tsinghua.edu.cn/archlinuxcn/$arch' >> /etc/pacman.conf");
}
void ustc(){
    system("echo 'Server = https://mirrors.ustc.edu.cn/archlinuxcn/$arch' >> /etc/pacman.conf");
}
void install_netease_music(){
    system("sudo pacman -S netease-music");
}
void solve_netease_music(){
    system("rm /usr/share/applications/netease-cloud-music.desktop");
    system("mv netease.cpp /usr/share/applications/netease-cloud-music.desktop");
}
int main(){
    //system("sudo su");
    cout<<"设置国内源;1:清华，2:ustc，其他：取消"<<endl;
    int sel=1;
    cin>>sel;
    
    if(sel==1){
        system("echo '[archlinuxcn]' >> /etc/pacman.conf");
        system("echo 'SigLevel = Optional TrustedOnly' >> /etc/pacman.conf");
        tringhua();
    }
    if(sel==2){
        system("echo '[archlinuxcn]' >> /etc/pacman.conf");
        system("echo 'SigLevel = Optional TrustedOnly' >> /etc/pacman.conf");
        ustc();
    }
    if(sel==1||sel==2){
        cout<<"升级中....."<<endl;
        system("sudo pacman -Syy");
        cout<<"导入密钥...."<<endl;
        system("sudo pacman -S archlinuxcn-keyring");
    }
    cout<<"是否安装中文输入法？"<<endl<<"1:是，其他：取消"<<endl;
    cin>>sel;
    if(sel==1){
        system("sudo pacman -S fcitx-im fcitx-configtool fcitx-sogoupinyin");
        cout<<"配置中文输入法...."<<endl;
        system("echo 'export GTK_IM_MODULE=fcitx' >> /etc/enviroment");
        system("echo 'export QT_IM_MODULE=fcitx' >> /etc/enviroment");
        system("echo 'export XMODIFIERS="@im=fcitx"' >> /etc/envirment");
    }
    cout<<"安装网易云音乐并解决中文输入问题...."<<endl;
    cout<<"是否安装网易云音乐并解决中文输入问题？"<<endl;
    cout<<"1->是；2->仅解决中文输入，其他：取消"<<endl;
    cin>>sel;
    if(sel==1){
        install_netease_music();
        solve_netease_music();
    }
    if(sel==2){
        solve_netease_music();
    }
    cout<<"解决deepin wine程序的运行...."<<endl;
    cout<<"还在开发中"<<endl;
    return 0;
        
}
