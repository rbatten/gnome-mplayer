/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * common.h
 * Copyright (C) Kevin DeKorte 2006 <kdekorte@gmail.com>
 * 
 * common.h is free software.
 * 
 * You may redistribute it and/or modify it under the terms of the
 * GNU General Public License, as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option)
 * any later version.
 * 
 * common.h is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with common.h.  If not, write to:
 * 	The Free Software Foundation, Inc.,
 * 	51 Franklin Street, Fifth Floor
 * 	Boston, MA  02110-1301, USA.
 */

#include <gtk/gtk.h>

#ifndef _COMMON_H
#define _COMMON_H

#define CACHE_SIZE		"/apps/gnome-mplayer/preferences/cache_size"
#define OSDLEVEL		"/apps/gnome-mplayer/preferences/osdlevel"
#define PPLEVEL		"/apps/gnome-mplayer/preferences/pplevel"
#define SOFTVOL			"/apps/gnome-mplayer/preferences/softvol"
#define VERBOSE			"/apps/gnome-mplayer/preferences/verbose"
#define VERTICAL		"/apps/gnome-mplayer/preferences/vertical"
#define FORCECACHE		"/apps/gnome-mplayer/preferences/forcecache"
#define LAST_DIR		"/apps/gnome-mplayer/preferences/last_dir"
#define SHOWPLAYLIST	"/apps/gnome-mplayer/preferences/showplaylist"
#define DISABLEASS          "/apps/gnome-mplayer/preferences/disableass"
#define DISABLEEMBEDDEDFONTS    "/apps/gnome-mplayer/preferences/disableembeddedfonts"
#define DISABLEFRAMEDROP	"/apps/gnome-mplayer/preferences/disableframedrop"
#define DISABLEFULLSCREEN	"/apps/gnome-mplayer/preferences/disablefullscreen"
#define DISABLECONTEXTMENU	"/apps/gnome-mplayer/preferences/disablecontextmenu"
#define SUBTITLEFONT	"/apps/gnome-mplayer/preferences/subtitlefont"
#define SUBTITLESCALE	"/apps/gnome-mplayer/preferences/subtitlescale"
#define SUBTITLECODEPAGE	"/apps/gnome-mplayer/preferences/subtitlecodepage"
#define SUBTITLECOLOR	"/apps/gnome-mplayer/preferences/subtitlecolor"

#define EXTRAOPTS		"/apps/gnome-mplayer/preferences/extraopts"

#define DISABLE_QT		"/apps/gecko-mediaplayer/preferences/disable_qt"
#define DISABLE_REAL	"/apps/gecko-mediaplayer/preferences/disable_real"
#define DISABLE_WMP		"/apps/gecko-mediaplayer/preferences/disable_wmp"
#define DISABLE_DVX		"/apps/gecko-mediaplayer/preferences/disable_dvx"


// JavaScript Playstates
#define STATE_UNDEFINED     0
#define STATE_STOPPED       1
#define STATE_PAUSED        2
#define STATE_PLAYING       3
#define STATE_SCANFORWARD   4
#define STATE_SCANREVERSE   5
#define STATE_BUFFERING	    6
#define STATE_WAITING       7
#define STATE_MEDIAENDED    8
#define STATE_TRANSITIONING 9
#define STATE_READY	        10
#define STATE_RECONNECTING  11


typedef enum {
    PLAYING,
    PAUSED,
    STOPPED,
    QUIT
} PLAYSTATE;

typedef enum {
    NO_ERROR,
    ERROR_RETRY_WITH_PLAYLIST
} PLAYBACK_ERROR;

PLAYSTATE state;
PLAYSTATE guistate;
PLAYSTATE lastguistate;
PLAYBACK_ERROR playback_error;

typedef struct _IdleData {
    gchar info[1024];
    gchar media_info[2048];
    gchar url[1024];
    gdouble percent;
    gdouble cachepercent;
    gint streaming;
    gchar progress_text[1024];
    gdouble volume;
    gint mute;
    gchar vol_tooltip[128];
    gint x;
    gint y;
    gint last_x;
    gint last_y;
    gint width;
    gint height;
    gint videopresent;
    gboolean fullscreen;
    gboolean showcontrols;
    gdouble position;
    gdouble length;
    gint byte_pos;
    gint brightness;
    gint contrast;
    gint gamma;
    gint hue;
    gint saturation;
    gchar video_format[64];
    gchar video_codec[16];
    gchar video_fps[16];
    gchar video_bitrate[16];
    gchar audio_codec[16];
    gchar audio_bitrate[16];
    gchar audio_samplerate[16];
    gchar audio_channels[16];
    gchar metadata[1024];
    gboolean fromdbus;
} IdleData;

IdleData *idledata;


typedef struct _ThreadData {
    gchar filename[1024];
    gchar subtitle[1024];
    gint streaming;
    gint player_window;
    gint playlist;
    gboolean done;
} ThreadData;

enum {
    ITEM_COLUMN,
    DESCRIPTION_COLUMN,
    COUNT_COLUMN,
    PLAYLIST_COLUMN,
    ARTIST_COLUMN,
    LENGTH_COLUMN,
    SUBTITLE_COLUMN,
    N_COLUMNS
};

//Define MIME for DnD
#define DRAG_NAME_0		"text/plain"
#define DRAG_INFO_0		0
#define DRAG_NAME_1		"text/uri-list"
#define DRAG_INFO_1		1
#define DRAG_NAME_2		"STRING"
#define DRAG_INFO_2		2

gchar *lastfile;
gint cache_size;
gboolean forcecache;
gint osdlevel;
gint pplevel;
gint streaming;
gint showcontrols;
gint fullscreen;
gint videopresent;
gint playlist;
gint embed_window;
gint window_x;
gint window_y;
gint control_id;
gboolean softvol;
gint verbose;
gint autostart;
gint actual_x, actual_y;
gint play_x, play_y;
gint last_x, last_y;
gint last_window_width, last_window_height;
gint stored_window_width, stored_window_height;
gchar vm[10];
gchar *vo;
gchar *ao;
gboolean disable_framedrop;
gboolean disable_context_menu;
gboolean disable_fullscreen;
gint loop;
gint random_order;
gboolean dontplaynext;
gboolean autopause;
gchar *path;
gint js_state;
gchar *rpname;
gchar *rpconsole;
gchar *rpcontrols;
gboolean show_media_label;
gboolean control_instance;
gchar *playlistname;
gboolean ok_to_play;
gchar *subtitle;
gchar *alang;
gchar *slang;
gint volume;
gboolean vertical_layout;
gboolean playlist_visible;
gboolean restore_playlist;
gboolean disable_ass;
gboolean disable_embeddedfonts;
gchar *subtitlefont;
gdouble subtitle_scale;
gchar *subtitle_codepage;
gchar *subtitle_color;
gboolean quit_on_complete;
gchar *extraopts;

// tv stuff
gchar *tv_device;
gchar *tv_driver;
gchar *tv_input;
gint tv_width;
gint tv_height;
gint tv_fps;

GThread *thread;
GMutex *slide_away;

gboolean qt_disabled;
gboolean real_disabled;
gboolean wmp_disabled;
gboolean dvx_disabled;

// playlist stuff
GtkListStore *playliststore;
GtkListStore *nonrandomplayliststore;
GtkTreeIter iter;
GtkTreeSelection *selection;
GtkWidget *list;

GtkWidget *create_window(gint windowid);
gint get_player_window();
gboolean hide_buttons(void *data);
gboolean show_copyurl(void *data);
gboolean set_media_info(void *data);
gboolean set_media_info_name(gchar * filename);
gboolean set_media_label(void *data);
gboolean set_progress_value(void *data);
gboolean set_progress_text(void *data);
gboolean set_progress_time(void *data);
gboolean set_volume_from_slider(gpointer data);
gboolean set_volume_tip(void *data);
gboolean set_gui_state(void *data);
gboolean resize_window(void *data);
gboolean set_play(void *data);
gboolean set_pause(void *data);
gboolean set_stop(void *data);
gboolean set_ff(void *data);
gboolean set_rew(void *data);
gboolean set_prev(void *data);
gboolean set_next(void *data);
gboolean set_quit(void *data);
gboolean set_position(void *data);
gboolean set_volume(void *data);
gboolean set_fullscreen(void *data);
gboolean set_show_controls(void *data);
gboolean set_window_visible(void *data);
gboolean make_panel_and_mouse_invisible(gpointer data);
void make_button(gchar * src, gchar * href);
void dbus_open_by_hrefid(gchar * hrefid);
void dbus_open_next();
void dbus_cancel();
void dbus_reload_plugins();
void dbus_send_rpsignal(gchar * signal);
void dbus_send_rpsignal_with_int(gchar * signal, int value);
void dbus_send_rpsignal_with_double(gchar * signal, gdouble value);
void dbus_send_rpsignal_with_string(gchar * signal, gchar * value);
void dbus_send_event(gchar * event, gint button);
void dbus_unhook();
void dbus_enable_screensaver();
void dbus_disable_screensaver();

void shutdown();
gpointer launch_player(gpointer data);

gboolean update_mplayer_config();
gboolean read_mplayer_config();

#endif                          /* _COMMON_H */