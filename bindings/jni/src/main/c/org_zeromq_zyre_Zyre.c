/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
#include <stdio.h>
#include <stdlib.h>
#include <jni.h>
#include "zyre.h"
#include "org_zeromq_zyre_Zyre.h"

JNIEXPORT jlong JNICALL
Java_org_zeromq_zyre_Zyre__1_1new (JNIEnv *env, jclass c, jstring name)
{
    char *name_ = (char *) (*env)->GetStringUTFChars (env, name, NULL);
    //  Disable CZMQ signal handling; allow Java to deal with it
    zsys_handler_set (NULL);
    jlong new_ = (jlong) (intptr_t) zyre_new (name_);
    (*env)->ReleaseStringUTFChars (env, name, name_);
    return new_;
}

JNIEXPORT void JNICALL
Java_org_zeromq_zyre_Zyre__1_1destroy (JNIEnv *env, jclass c, jlong self)
{
    zyre_destroy ((zyre_t **) &self);
}

JNIEXPORT jstring JNICALL
Java_org_zeromq_zyre_Zyre__1_1uuid (JNIEnv *env, jclass c, jlong self)
{
    char *uuid_ = (char *) zyre_uuid ((zyre_t *) (intptr_t) self);
    jstring return_string_ = (*env)->NewStringUTF (env, uuid_);
    return return_string_;
}

JNIEXPORT jstring JNICALL
Java_org_zeromq_zyre_Zyre__1_1name (JNIEnv *env, jclass c, jlong self)
{
    char *name_ = (char *) zyre_name ((zyre_t *) (intptr_t) self);
    jstring return_string_ = (*env)->NewStringUTF (env, name_);
    return return_string_;
}

JNIEXPORT void JNICALL
Java_org_zeromq_zyre_Zyre__1_1setName (JNIEnv *env, jclass c, jlong self, jstring name)
{
    char *name_ = (char *) (*env)->GetStringUTFChars (env, name, NULL);
    zyre_set_name ((zyre_t *) (intptr_t) self, name_);
    (*env)->ReleaseStringUTFChars (env, name, name_);
}

JNIEXPORT void JNICALL
Java_org_zeromq_zyre_Zyre__1_1setHeader (JNIEnv *env, jclass c, jlong self, jstring name, jstring format)
{
    char *name_ = (char *) (*env)->GetStringUTFChars (env, name, NULL);
    char *format_ = (char *) (*env)->GetStringUTFChars (env, format, NULL);
    zyre_set_header ((zyre_t *) (intptr_t) self, name_, "%s", format_);
    (*env)->ReleaseStringUTFChars (env, name, name_);
    (*env)->ReleaseStringUTFChars (env, format, format_);
}

JNIEXPORT void JNICALL
Java_org_zeromq_zyre_Zyre__1_1setVerbose (JNIEnv *env, jclass c, jlong self)
{
    zyre_set_verbose ((zyre_t *) (intptr_t) self);
}

JNIEXPORT void JNICALL
Java_org_zeromq_zyre_Zyre__1_1setPort (JNIEnv *env, jclass c, jlong self, jint port_nbr)
{
    zyre_set_port ((zyre_t *) (intptr_t) self, (int) port_nbr);
}

JNIEXPORT void JNICALL
Java_org_zeromq_zyre_Zyre__1_1setEphemeralPort (JNIEnv *env, jclass c, jlong self, jint port_nbr)
{
    zyre_set_ephemeral_port ((zyre_t *) (intptr_t) self, (int) port_nbr);
}

JNIEXPORT void JNICALL
Java_org_zeromq_zyre_Zyre__1_1setEvasiveTimeout (JNIEnv *env, jclass c, jlong self, jint interval)
{
    zyre_set_evasive_timeout ((zyre_t *) (intptr_t) self, (int) interval);
}

JNIEXPORT void JNICALL
Java_org_zeromq_zyre_Zyre__1_1setExpiredTimeout (JNIEnv *env, jclass c, jlong self, jint interval)
{
    zyre_set_expired_timeout ((zyre_t *) (intptr_t) self, (int) interval);
}

JNIEXPORT void JNICALL
Java_org_zeromq_zyre_Zyre__1_1setInterval (JNIEnv *env, jclass c, jlong self, jlong interval)
{
    zyre_set_interval ((zyre_t *) (intptr_t) self, (size_t) interval);
}

JNIEXPORT void JNICALL
Java_org_zeromq_zyre_Zyre__1_1setInterface (JNIEnv *env, jclass c, jlong self, jstring value)
{
    char *value_ = (char *) (*env)->GetStringUTFChars (env, value, NULL);
    zyre_set_interface ((zyre_t *) (intptr_t) self, value_);
    (*env)->ReleaseStringUTFChars (env, value, value_);
}

JNIEXPORT jint JNICALL
Java_org_zeromq_zyre_Zyre__1_1setEndpoint (JNIEnv *env, jclass c, jlong self, jstring format)
{
    char *format_ = (char *) (*env)->GetStringUTFChars (env, format, NULL);
    jint set_endpoint_ = (jint) zyre_set_endpoint ((zyre_t *) (intptr_t) self, "%s", format_);
    (*env)->ReleaseStringUTFChars (env, format, format_);
    return set_endpoint_;
}

JNIEXPORT void JNICALL
Java_org_zeromq_zyre_Zyre__1_1setContestInGroup (JNIEnv *env, jclass c, jlong self, jstring group)
{
    char *group_ = (char *) (*env)->GetStringUTFChars (env, group, NULL);
    zyre_set_contest_in_group ((zyre_t *) (intptr_t) self, group_);
    (*env)->ReleaseStringUTFChars (env, group, group_);
}

JNIEXPORT void JNICALL
Java_org_zeromq_zyre_Zyre__1_1setAdvertisedEndpoint (JNIEnv *env, jclass c, jlong self, jstring value)
{
    char *value_ = (char *) (*env)->GetStringUTFChars (env, value, NULL);
    zyre_set_advertised_endpoint ((zyre_t *) (intptr_t) self, value_);
    (*env)->ReleaseStringUTFChars (env, value, value_);
}

JNIEXPORT void JNICALL
Java_org_zeromq_zyre_Zyre__1_1setZcert (JNIEnv *env, jclass c, jlong self, jlong zcert)
{
    zyre_set_zcert ((zyre_t *) (intptr_t) self, (zcert_t *) (intptr_t) zcert);
}

JNIEXPORT void JNICALL
Java_org_zeromq_zyre_Zyre__1_1setZapDomain (JNIEnv *env, jclass c, jlong self, jstring domain)
{
    char *domain_ = (char *) (*env)->GetStringUTFChars (env, domain, NULL);
    zyre_set_zap_domain ((zyre_t *) (intptr_t) self, domain_);
    (*env)->ReleaseStringUTFChars (env, domain, domain_);
}

JNIEXPORT void JNICALL
Java_org_zeromq_zyre_Zyre__1_1gossipBind (JNIEnv *env, jclass c, jlong self, jstring format)
{
    char *format_ = (char *) (*env)->GetStringUTFChars (env, format, NULL);
    zyre_gossip_bind ((zyre_t *) (intptr_t) self, "%s", format_);
    (*env)->ReleaseStringUTFChars (env, format, format_);
}

JNIEXPORT void JNICALL
Java_org_zeromq_zyre_Zyre__1_1gossipConnect (JNIEnv *env, jclass c, jlong self, jstring format)
{
    char *format_ = (char *) (*env)->GetStringUTFChars (env, format, NULL);
    zyre_gossip_connect ((zyre_t *) (intptr_t) self, "%s", format_);
    (*env)->ReleaseStringUTFChars (env, format, format_);
}

JNIEXPORT void JNICALL
Java_org_zeromq_zyre_Zyre__1_1gossipConnectCurve (JNIEnv *env, jclass c, jlong self, jstring public_key, jstring format)
{
    char *public_key_ = (char *) (*env)->GetStringUTFChars (env, public_key, NULL);
    char *format_ = (char *) (*env)->GetStringUTFChars (env, format, NULL);
    zyre_gossip_connect_curve ((zyre_t *) (intptr_t) self, public_key_, "%s", format_);
    (*env)->ReleaseStringUTFChars (env, public_key, public_key_);
    (*env)->ReleaseStringUTFChars (env, format, format_);
}

JNIEXPORT jint JNICALL
Java_org_zeromq_zyre_Zyre__1_1start (JNIEnv *env, jclass c, jlong self)
{
    jint start_ = (jint) zyre_start ((zyre_t *) (intptr_t) self);
    return start_;
}

JNIEXPORT void JNICALL
Java_org_zeromq_zyre_Zyre__1_1stop (JNIEnv *env, jclass c, jlong self)
{
    zyre_stop ((zyre_t *) (intptr_t) self);
}

JNIEXPORT jint JNICALL
Java_org_zeromq_zyre_Zyre__1_1join (JNIEnv *env, jclass c, jlong self, jstring group)
{
    char *group_ = (char *) (*env)->GetStringUTFChars (env, group, NULL);
    jint join_ = (jint) zyre_join ((zyre_t *) (intptr_t) self, group_);
    (*env)->ReleaseStringUTFChars (env, group, group_);
    return join_;
}

JNIEXPORT jint JNICALL
Java_org_zeromq_zyre_Zyre__1_1leave (JNIEnv *env, jclass c, jlong self, jstring group)
{
    char *group_ = (char *) (*env)->GetStringUTFChars (env, group, NULL);
    jint leave_ = (jint) zyre_leave ((zyre_t *) (intptr_t) self, group_);
    (*env)->ReleaseStringUTFChars (env, group, group_);
    return leave_;
}

JNIEXPORT jlong JNICALL
Java_org_zeromq_zyre_Zyre__1_1recv (JNIEnv *env, jclass c, jlong self)
{
    jlong recv_ = (jlong) (intptr_t) zyre_recv ((zyre_t *) (intptr_t) self);
    return recv_;
}

JNIEXPORT jint JNICALL
Java_org_zeromq_zyre_Zyre__1_1whisper (JNIEnv *env, jclass c, jlong self, jstring peer, jlong msg_p)
{
    char *peer_ = (char *) (*env)->GetStringUTFChars (env, peer, NULL);
    jint whisper_ = (jint) zyre_whisper ((zyre_t *) (intptr_t) self, peer_, (zmsg_t **) (intptr_t) &msg_p);
    (*env)->ReleaseStringUTFChars (env, peer, peer_);
    return whisper_;
}

JNIEXPORT jint JNICALL
Java_org_zeromq_zyre_Zyre__1_1shout (JNIEnv *env, jclass c, jlong self, jstring group, jlong msg_p)
{
    char *group_ = (char *) (*env)->GetStringUTFChars (env, group, NULL);
    jint shout_ = (jint) zyre_shout ((zyre_t *) (intptr_t) self, group_, (zmsg_t **) (intptr_t) &msg_p);
    (*env)->ReleaseStringUTFChars (env, group, group_);
    return shout_;
}

JNIEXPORT jint JNICALL
Java_org_zeromq_zyre_Zyre__1_1whispers (JNIEnv *env, jclass c, jlong self, jstring peer, jstring format)
{
    char *peer_ = (char *) (*env)->GetStringUTFChars (env, peer, NULL);
    char *format_ = (char *) (*env)->GetStringUTFChars (env, format, NULL);
    jint whispers_ = (jint) zyre_whispers ((zyre_t *) (intptr_t) self, peer_, "%s", format_);
    (*env)->ReleaseStringUTFChars (env, peer, peer_);
    (*env)->ReleaseStringUTFChars (env, format, format_);
    return whispers_;
}

JNIEXPORT jint JNICALL
Java_org_zeromq_zyre_Zyre__1_1shouts (JNIEnv *env, jclass c, jlong self, jstring group, jstring format)
{
    char *group_ = (char *) (*env)->GetStringUTFChars (env, group, NULL);
    char *format_ = (char *) (*env)->GetStringUTFChars (env, format, NULL);
    jint shouts_ = (jint) zyre_shouts ((zyre_t *) (intptr_t) self, group_, "%s", format_);
    (*env)->ReleaseStringUTFChars (env, group, group_);
    (*env)->ReleaseStringUTFChars (env, format, format_);
    return shouts_;
}

JNIEXPORT jlong JNICALL
Java_org_zeromq_zyre_Zyre__1_1peers (JNIEnv *env, jclass c, jlong self)
{
    jlong peers_ = (jlong) (intptr_t) zyre_peers ((zyre_t *) (intptr_t) self);
    return peers_;
}

JNIEXPORT jlong JNICALL
Java_org_zeromq_zyre_Zyre__1_1peersByGroup (JNIEnv *env, jclass c, jlong self, jstring name)
{
    char *name_ = (char *) (*env)->GetStringUTFChars (env, name, NULL);
    jlong peers_by_group_ = (jlong) (intptr_t) zyre_peers_by_group ((zyre_t *) (intptr_t) self, name_);
    (*env)->ReleaseStringUTFChars (env, name, name_);
    return peers_by_group_;
}

JNIEXPORT jlong JNICALL
Java_org_zeromq_zyre_Zyre__1_1ownGroups (JNIEnv *env, jclass c, jlong self)
{
    jlong own_groups_ = (jlong) (intptr_t) zyre_own_groups ((zyre_t *) (intptr_t) self);
    return own_groups_;
}

JNIEXPORT jlong JNICALL
Java_org_zeromq_zyre_Zyre__1_1peerGroups (JNIEnv *env, jclass c, jlong self)
{
    jlong peer_groups_ = (jlong) (intptr_t) zyre_peer_groups ((zyre_t *) (intptr_t) self);
    return peer_groups_;
}

JNIEXPORT jstring JNICALL
Java_org_zeromq_zyre_Zyre__1_1peerAddress (JNIEnv *env, jclass c, jlong self, jstring peer)
{
    char *peer_ = (char *) (*env)->GetStringUTFChars (env, peer, NULL);
    char *peer_address_ = (char *) zyre_peer_address ((zyre_t *) (intptr_t) self, peer_);
    jstring return_string_ = (*env)->NewStringUTF (env, peer_address_);
    zstr_free (&peer_address_);
    (*env)->ReleaseStringUTFChars (env, peer, peer_);
    return return_string_;
}

JNIEXPORT jstring JNICALL
Java_org_zeromq_zyre_Zyre__1_1peerHeaderValue (JNIEnv *env, jclass c, jlong self, jstring peer, jstring name)
{
    char *peer_ = (char *) (*env)->GetStringUTFChars (env, peer, NULL);
    char *name_ = (char *) (*env)->GetStringUTFChars (env, name, NULL);
    char *peer_header_value_ = (char *) zyre_peer_header_value ((zyre_t *) (intptr_t) self, peer_, name_);
    jstring return_string_ = (*env)->NewStringUTF (env, peer_header_value_);
    zstr_free (&peer_header_value_);
    (*env)->ReleaseStringUTFChars (env, peer, peer_);
    (*env)->ReleaseStringUTFChars (env, name, name_);
    return return_string_;
}

JNIEXPORT jint JNICALL
Java_org_zeromq_zyre_Zyre__1_1requirePeer (JNIEnv *env, jclass c, jlong self, jstring uuid, jstring endpoint, jstring public_key)
{
    char *uuid_ = (char *) (*env)->GetStringUTFChars (env, uuid, NULL);
    char *endpoint_ = (char *) (*env)->GetStringUTFChars (env, endpoint, NULL);
    char *public_key_ = (char *) (*env)->GetStringUTFChars (env, public_key, NULL);
    jint require_peer_ = (jint) zyre_require_peer ((zyre_t *) (intptr_t) self, uuid_, endpoint_, public_key_);
    (*env)->ReleaseStringUTFChars (env, uuid, uuid_);
    (*env)->ReleaseStringUTFChars (env, endpoint, endpoint_);
    (*env)->ReleaseStringUTFChars (env, public_key, public_key_);
    return require_peer_;
}

JNIEXPORT jlong JNICALL
Java_org_zeromq_zyre_Zyre__1_1socket (JNIEnv *env, jclass c, jlong self)
{
    jlong socket_ = (jlong) (intptr_t) zyre_socket ((zyre_t *) (intptr_t) self);
    return socket_;
}

JNIEXPORT void JNICALL
Java_org_zeromq_zyre_Zyre__1_1print (JNIEnv *env, jclass c, jlong self)
{
    zyre_print ((zyre_t *) (intptr_t) self);
}

JNIEXPORT jlong JNICALL
Java_org_zeromq_zyre_Zyre__1_1version (JNIEnv *env, jclass c)
{
    jlong version_ = (jlong) zyre_version ();
    return version_;
}

JNIEXPORT void JNICALL
Java_org_zeromq_zyre_Zyre__1_1test (JNIEnv *env, jclass c, jboolean verbose)
{
    zyre_test ((bool) verbose);
}

