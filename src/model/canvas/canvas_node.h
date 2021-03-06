/**
 * canvas_node.h
 * Node (pixel) in a canvas
 * Author:		Elias Mawa
 * Created on: 	10-16-2019
 * Last Edit:	12-04-2019
 */

#ifndef CANVAS_NODE_H
#define CANVAS_NODE_H

#include "../../global.h"
#include "../object.h"

#include "../../type/direction_type.h"

/** 
 * Representation of a node (pixel) on a canvas
 */
class CanvasNode : private Object
{
public:
	/* Constructors & Deconstructors */

	/** 
	 * Create a node with a specified x & y location
	 * @param x The x location of node
	 * @param y The y location of node
	 */
    CanvasNode(float x, float y);

    ~CanvasNode();

	/* Functions */

	/** Draw the node */
    void draw();
	/** Update the node */
    void update();

	/** Set the rgb value of the node  */
	void paint(int r, int g, int b);

	///////////////////////////
	//	Getters
	///////////////////////////

	/** Get the neighbor of the node in the specified direction */
	CanvasNode* getLink(DIRECTION direction);

	/** Get visibility flag */
	bool isVisible();

	///////////////////////////
	//	Setters
	///////////////////////////

	/** 
	 * Set the color of the node
	 * @param red Red value.
	 * @param green Green value.
	 * @param blue Blue value.
	 * @param alpha Alpha value.
	 **/
	void setColor(int red, int green, int blue, float alpha = 1.0f);

	/** Set the node as visible */
	void setVisible() { visible = true; }
	/** Set the node as invisible */
	void setInvisible() { visible = false; }

	/**
	 * Set the neightbor of the node in the specified direction
	 * @param node The node that is going to be connected.
	 * @param direction The direction the node is in.
	 **/
	void setLink(CanvasNode* node, DIRECTION direction);

	int getR() { return r; }
	int getG() { return g; }
	int getB() { return b; }
	int getA() { return a; }
private:
	/** width of the node */
	int width = 2/32;
	/** height of the node */
	int height = width;

	/** North link */
	CanvasNode* n;
	/** South link */
	CanvasNode* s;
	/** East link */
	CanvasNode* e;
	/** West link */
	CanvasNode* w;

	/** Visiblity flag for node */
	bool visible = false;

	/** Red level */
	int r;
	/** Green level */
	int g;
	/** Blue level */
	int b;
	/** Alpha level */
	float a;

	/** x location of node */
	float x;
	/** y location of node */
	float y;
};

#endif // CANVAS_H
