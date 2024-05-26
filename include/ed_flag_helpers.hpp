#ifndef EDFLAGHELPERS_INCLUDED
#define EDFLAGHELPERS_INCLUDED
namespace edflags {
    const uint32_t Docked = 1<<0;             // on a landing pad
    const uint32_t Landed = 1<<1;             // on planet surface
    const uint32_t LandingGearDown = 1<<2;
    const uint32_t ShieldsUp = 1<<3;
    const uint32_t Supercruise = 1<<4;
    const uint32_t FlightAssistOff = 1<<5;
    const uint32_t HardpointsDeployed = 1<<6;
    const uint32_t InWing = 1<<7;
    const uint32_t LightsOn = 1<<8;
    const uint32_t CargoScoopDeployed = 1<<9;
    const uint32_t SilentRunning = 1<<10;
    const uint32_t ScoopingFuel = 1<<11;
    const uint32_t SrvHandbrake = 1<<12;
    const uint32_t SrvTurret = 1<<13;         // using turret view
    const uint32_t SrvUnderShip = 1<<14;      //turret retracted
    const uint32_t SrvDriveAssist = 1<<15;
    const uint32_t FsdMassLocked = 1<<16;
    const uint32_t FsdCharging = 1<<17;
    const uint32_t FsdCooldown = 1<<18;
    const uint32_t LowFuel = 1<<19;           // < 25%
    const uint32_t OverHeating = 1<<20;       // > 100%, or is this 80% now ?
    const uint32_t HasLatLong = 1<<21;
    const uint32_t IsInDanger = 1<<22;
    const uint32_t BeingInterdicted = 1<<23;
    const uint32_t InMainShip = 1<<24;
    const uint32_t InFighter = 1<<25;
    const uint32_t InSRV = 1<<26;
    const uint32_t AnalysisMode = 1<<27;      // Hud in Analysis mode
    const uint32_t NightVision = 1<<28;
    const uint32_t AverageAltitude = 1<<29;   // Altitude from Average radius
    const uint32_t FsdJump = 1<<30;
    const uint32_t SrvHighBeam = 1<<31;
}
namespace edflags2 {
    const uint32_t OnFoot = 1<<0;
    const uint32_t InTaxi = 1<<1;  // (or dropship/shuttle)
    const uint32_t InMulticrew = 1<<2;  // (ie in someone else’s ship)
    const uint32_t OnFootInStation = 1<<3;
    const uint32_t OnFootOnPlanet = 1<<4;
    const uint32_t AimDownSight = 1<<5;
    const uint32_t LowOxygen = 1<<6;
    const uint32_t LowHealth = 1<<7;
    const uint32_t Cold = 1<<8;
    const uint32_t Hot = 1<<9;
    const uint32_t VeryCold = 1<<10;
    const uint32_t VeryHot = 1<<11;
    const uint32_t GlideMode = 1<<12;
    const uint32_t OnFootInHangar = 1<<13;
    const uint32_t OnFootSocialSpace = 1<<14;
    const uint32_t OnFootExterior = 1<<15;
    const uint32_t BreathableAtmosphere = 1<<16;
    const uint32_t TelepresenceMulticrew = 1<<17;
    const uint32_t PhysicalMulticrew = 1<<18;
    const uint32_t HyperdriveCharging = 1<<19;
}

#endif