/*
 * GlobalEventFit.h
 *
 *  Created on: Apr 16, 2015
 *      Author: zotz
 */

#ifndef GlobalEventFit_h
#define GlobalEventFit_h

#include "SimpleFits/FitSoftware/interface/TPTRObject.h"
#include "SimpleFits/FitSoftware/interface/GEFObject.h"
#include "SimpleFits/FitSoftware/interface/LorentzVectorParticle.h"
#include "SimpleFits/FitSoftware/interface/Logger.h"
#include "SimpleFits/FitSoftware/interface/TrackParticle.h"

class GlobalEventFit{
  public:
	GlobalEventFit(TrackParticle Muon, LorentzVectorParticle A1, double Phi_Res, TVector3 PV, TMatrixTSym<double> PVCov);
	virtual ~GlobalEventFit();

	GEFObject Fit();
	bool AmbiguitySolverByChi2(std::vector<bool> A1Fit, std::vector<bool> EventFit, std::vector<double> Chi2s, int &IndexToReturn);

	const LorentzVectorParticle& getA1() const{ return A1_;}
	const GEFObject& getGEFObject() const{ return GEFObject_;}
	
	bool isConfigured() const{return isConfigured_;}
	bool isFit() const{return isFit_;}
	
	const TrackParticle& getMuon() const{return Muon_;}
	const TVector3& getPV() const{return PV_;}
	const TMatrixTSym<double>& getPVCov() const{return PVCov_;}
	const TVector3& getSV() const{return SV_;}
	const TMatrixTSym<double>& getSVCov() const{return SVCov_;}
	const TPTRObject& getTPTRObject() const{return TPTRObject_;}

  protected:
	TPTRObject ThreeProngTauReco();
	bool IsAmbiguous(std::vector<bool> recostatus);

  private:
	bool isConfigured_;
	bool isFit_;
	TPTRObject TPTRObject_;
	GEFObject GEFObject_;
	TrackParticle Muon_;
	LorentzVectorParticle A1_;
	TVector3 PV_, SV_;
	TMatrixTSym<double> PVCov_, SVCov_;
	bool useMassConstraint_;
	double MassConstraint_;
	double Phi_Res_;
};


#endif /* GlobalEventFit_h */
