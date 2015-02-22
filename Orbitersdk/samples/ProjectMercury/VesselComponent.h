#pragma once

class MercuryCapsule;

class VesselComponent
{
public:
	VesselComponent(MercuryCapsule* vessel);
	virtual ~VesselComponent();

protected:
	MercuryCapsule* pVessel;
};