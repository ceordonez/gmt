/*--------------------------------------------------------------------
 *	$Id$
 *
 *	Copyright (c) 1991-2014 by P. Wessel, W. H. F. Smith, R. Scharroo, J. Luis and F. Wobbe
 *	See LICENSE.TXT file for copying and redistribution conditions.
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU Lesser General Public License as published by
 *	the Free Software Foundation; version 3 or any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU Lesser General Public License for more details.
 *
 *	Contact info: gmt.soest.hawaii.edu
 *--------------------------------------------------------------------*/
/*
 * gmt_ps.h contains definition of the structure with PostScript settings.
 *
 * Author:	Paul Wessel
 * Date:	01-OCT-2009
 * Version:	5 API
 */

/*!
 * \file gmt_ps.h
 * \brief Definition of the structure with PostScript settings 
 */

#ifndef _GMT_PS_H
#define _GMT_PS_H

/*--------------------------------------------------------------------
 *			GMT PS STRUCTURE DEFINITION
 *--------------------------------------------------------------------*/

/* Several parameters control the running of PSL.  Some are found among
 * the GMT default settings (e.g., PS_PAGE_COLOR) and these values are
 * parsed by the default machinery and stored in the corresponding
 * GMT->setting.ps_* parameters, e.g., PS_PAGE_COLOR is parsed and stored
 * as GMT->setting.ps_page_color.  All of these are used as arguments to
 * PSL_beginsession, PSL_set_defaults, and PSL_beginplot which sets teh
 * internal PSL variables.
 * A few of these parameters can also be modified via the GMT command
 * line options: -P -U -X -Y -c.  These options simply change the values as
 * currently stored in the corresponding GMT_->setting.ps_*.  Note that
 * -U has a default position and justification and thus controlled by the
 * MAP_LOGO_* parameters GMT->setting.ps_map_logo_* while the actual label is
 * kept in the structure below as given by -U.
 * Finally, there are a few PSL variables that are not initialized via
 * PSL_beginsession, PSL_set_defaults, or PSL_plotbegin, such as the
 * transparency or line_cap settings.  These are all GMT default settings
 * that are parsed directly into the PSL internal variables.
 */

/*! PSL settings affected by GMT options -X -Y -U and clipping */
struct GMT_PS {
	/* A structure pointer is passed to GMT_plotinit which calls ps_plotinit */
	int nclip;				/* +1 if clipping will extend beyond current process, -1 if we terminate clipping */
	int clip_level;		/* Sum total clip level, should be zero at end of command sequence */
	int layer;		/* Layer number starting at 1 and incremented for each GMT layer added */
	char map_logo_label[GMT_BUFSIZ];		/* Label added to GMT time stamp generated by -U */
	char origin[2];				/* Defines the origin of the map offset ('r', 'a', 'c', or 'f') */
};

#endif  /* _GMT_PS_H */
