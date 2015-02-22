#include "VesselComponent.h"
#include "MercuryCapsule.h"

VesselComponent::VesselComponent(MercuryCapsule* vessel)
{
	pVessel = vessel;
}

VesselComponent::~VesselComponent()
{

}