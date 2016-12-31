//
//  main.cpp
//  cityJason
//
//  Created by LayneHuang on 2016/12/30.
//  Copyright © 2016年 LayneHuang. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <fstream>
using namespace std;

char s[111];
char province[111];
char city[111];
char display[111];


vector<string>vec;
/*
 整合中国的所有城市信息作为JSON
 */
int main(int argc, const char * argv[]) {
//    
//
//    int first = 1 ;
//    
//    freopen("/Users/laynehuang/Desktop/cityJason/cityJason/in","r",stdin);
//    //freopen("/Users/laynehuang/Desktop/cityJason/cityJason/out","w",stdout);
//    
//    
//    cout << "[" << endl ;
//    while( cin >> s ) {
//        
//        
//        int len = (int)strlen(s);
//        if( len == 0 ) continue ;
//
//        
//        if( s[len-1] == ':' ) {
//            
//            for( int i = 0 ; i < len ; ++i ) {
//                province[i] = s[i] ;
//            } province[len-1] = 0 ;
//            
//        } else {
//            if( !first ) {
//                
//                cout << "}," << endl ;
//            }
//            
//            cout << "{" << endl ;
//            
//            int j = 0 , lenCity = 0 ;
//            for( int i = 0 ; i < len ; ++i ) {
//                if( province[i] == s[i] ) j = i ;
//                else break ;
//            }
//            for( ; j < len ; ++j ) {
//                city[lenCity++] = s[j] ;
//            } city[lenCity] = 0 ;
//            
//            
//            cout << "\"province\":\"" << province << "\"," << endl ;
//        
//            cout << "\"display\":\"" ;
//            for(int i = 0 ; i < lenCity ; ++i ) {
//                if( city[i] == '\\') continue ;
//                if( city[i] <= '9' && city[i] >= '0' ) continue ;
//                cout << city[i] ;
//            }
//            cout << "\"," << endl ;
//            
//            cout << "\"query\":\"" ;
//            for(int i = 0 ; i < lenCity ; ++i ) {
//                if( city[i] == '\\') continue ;
//                if( city[i] <= '9' && city[i] >= '0' ) continue ;
//                cout << city[i] ;
//            }
//            cout << "\"" << endl ;
//            
//            first = 0 ;
//        }
//    }
//    cout << "}" << endl ;
//    cout << "]" << endl ;
    
    
//    
//    freopen("/Users/laynehuang/Desktop/cityJason/cityJason/pinyin","r",stdin);
//    freopen("/Users/laynehuang/Desktop/cityJason/cityJason/pinyin_res","w",stdout);
//    while( cin >> s ) {
//        int len = 0 ;
//        for( int i = 0 ; i < strlen(s) ; ++i ) {
//            if( s[i] <= 'z' && s[i] >= 'a'  ) {
//                display[len++] = s[i] ;
//            } else if ( s[i] <= 'Z' && s[i] >= 'A') {
//                display[len++] = s[i] - 'A' + 'a' ;
//            }
//        } display[len] = 0 ; 
//        for( int i = 7 ; i < len ; ++i ) {
//            cout << display[i] ;
//        } cout << endl ;
//        
//    }

    
    
    freopen("/Users/laynehuang/Desktop/cityJason/cityJason/in2","r",stdin);
    freopen("/Users/laynehuang/Desktop/cityJason/cityJason/out2","w",stdout);
    int totPinyin = 0 ;
    int id = 0 ;
    int afterPinyin = 0 ;
    
    while( cin >> s ) {
        
        
        if( s[0] == '[' ) {
            afterPinyin = 1 ;
        }
        
        if( !afterPinyin ) {
            vec.push_back(s);
            totPinyin++ ;
        } else {
        
        
//        if( strlen(s) < 2 || s[1] != 'd' ) continue ;
    
    
            for( int i = 0 ; i < strlen(s) ; ++i ) {
                if( s[i] == '\\' || ( s[i] <= '9' && s[i] >= '0' ) )continue ;
                if( s[1] == 'd' && i + 5 >= strlen(s) && s[i] != '\"' && s[i] != ',' ) {
                    //cout << "fuck" << s[i] << endl ;
                    continue ;
                }
                cout << s[i] ;
            }
        
            if( s[strlen(s) - 1 ] != ':') cout << endl ;
            if( s[0] == '{' ) {
                cout << "\"id\":\"" << id <<"\"," << endl ;
                if( id >= (int) vec.size() ) {
                    cout << "BUG!!!!!!!!!!!!!" << endl ;
                }
                cout << "\"pinyin\":\"" << vec[id] <<"\"," << endl ;
                id++ ;
            
            }
        }
    }
    return 0;

}
