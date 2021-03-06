/*

g3data2 : A program for grabbing data from scanned graphs
Copyright (C) 2011 Jonas Frantz

    This file is part of g3data2.

    g3data2 is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    g3data2 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

Authors email : jonas@frantz.fi

 */

#include <gtk/gtk.h>
#include "main.h"

/****************************************************************/
/* This function draws the X-axis, Y-axis or point marker on	*/
/* the drawing_area depending on the value of the type		*/
/* parameter.							*/
/****************************************************************/
void drawMarker(cairo_t *cr, gint x, gint y, gint type) {

	if (type == 0) {
		cairo_move_to(cr, x - MARKERLENGTH - 1, y);
		cairo_rel_line_to(cr, MARKERLENGTH * 2 + 1, 0);
		cairo_move_to(cr, x, y);
		cairo_rel_line_to(cr, 0, -MARKERLENGTH);
		cairo_set_source_rgb(cr, 0, 1, 0);
		cairo_stroke(cr);
	} else if (type == 1) {
		cairo_move_to(cr, x, y - MARKERLENGTH - 1);
		cairo_rel_line_to(cr, 0, MARKERLENGTH * 2 + 1);
		cairo_move_to(cr, x, y);
		cairo_rel_line_to(cr, MARKERLENGTH, 0);
		cairo_set_source_rgb(cr, 0, 0, 1);
		cairo_stroke(cr);
	} else {
		cairo_rectangle(cr, x - MARKERSIZE, y - MARKERSIZE, MARKERSIZE * 2 + 1,
				MARKERSIZE * 2 + 1);
		cairo_set_source_rgb(cr, 1, 0, 0);
		cairo_stroke(cr);
	}
}
