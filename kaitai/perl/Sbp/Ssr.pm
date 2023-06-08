# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
use Sbp::Gnss;

use strict;
use warnings;
use IO::KaitaiStruct 0.009_000;

########################################################################
package Ssr;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

}

########################################################################
package Ssr::GridDefinitionHeaderDepA;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{region_size_inverse} = $self->{_io}->read_u1();
    $self->{area_width} = $self->{_io}->read_u2le();
    $self->{lat_nw_corner_enc} = $self->{_io}->read_u2le();
    $self->{lon_nw_corner_enc} = $self->{_io}->read_u2le();
    $self->{num_msgs} = $self->{_io}->read_u1();
    $self->{seq_num} = $self->{_io}->read_u1();
}

sub region_size_inverse {
    my ($self) = @_;
    return $self->{region_size_inverse};
}

sub area_width {
    my ($self) = @_;
    return $self->{area_width};
}

sub lat_nw_corner_enc {
    my ($self) = @_;
    return $self->{lat_nw_corner_enc};
}

sub lon_nw_corner_enc {
    my ($self) = @_;
    return $self->{lon_nw_corner_enc};
}

sub num_msgs {
    my ($self) = @_;
    return $self->{num_msgs};
}

sub seq_num {
    my ($self) = @_;
    return $self->{seq_num};
}

########################################################################
package Ssr::StecResidualNoStd;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{sv_id} = Gnss::SvId->new($self->{_io}, $self, $self->{_root});
    $self->{residual} = $self->{_io}->read_s2le();
}

sub sv_id {
    my ($self) = @_;
    return $self->{sv_id};
}

sub residual {
    my ($self) = @_;
    return $self->{residual};
}

########################################################################
package Ssr::TroposphericDelayCorrectionNoStd;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{hydro} = $self->{_io}->read_s2le();
    $self->{wet} = $self->{_io}->read_s1();
}

sub hydro {
    my ($self) = @_;
    return $self->{hydro};
}

sub wet {
    my ($self) = @_;
    return $self->{wet};
}

########################################################################
package Ssr::MsgSsrStecCorrectionDep;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{header} = Ssr::StecHeader->new($self->{_io}, $self, $self->{_root});
    $self->{stec_sat_list} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{stec_sat_list}}, Ssr::StecSatElement->new($self->{_io}, $self, $self->{_root});
    }
}

sub header {
    my ($self) = @_;
    return $self->{header};
}

sub stec_sat_list {
    my ($self) = @_;
    return $self->{stec_sat_list};
}

########################################################################
package Ssr::StecSatElementIntegrity;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{stec_residual} = Ssr::StecResidual->new($self->{_io}, $self, $self->{_root});
    $self->{stec_bound_mu} = $self->{_io}->read_u1();
    $self->{stec_bound_sig} = $self->{_io}->read_u1();
    $self->{stec_bound_mu_dot} = $self->{_io}->read_u1();
    $self->{stec_bound_sig_dot} = $self->{_io}->read_u1();
}

sub stec_residual {
    my ($self) = @_;
    return $self->{stec_residual};
}

sub stec_bound_mu {
    my ($self) = @_;
    return $self->{stec_bound_mu};
}

sub stec_bound_sig {
    my ($self) = @_;
    return $self->{stec_bound_sig};
}

sub stec_bound_mu_dot {
    my ($self) = @_;
    return $self->{stec_bound_mu_dot};
}

sub stec_bound_sig_dot {
    my ($self) = @_;
    return $self->{stec_bound_sig_dot};
}

########################################################################
package Ssr::MsgSsrOrbitClockDepA;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{time} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{sid} = Gnss::GnssSignal->new($self->{_io}, $self, $self->{_root});
    $self->{update_interval} = $self->{_io}->read_u1();
    $self->{iod_ssr} = $self->{_io}->read_u1();
    $self->{iod} = $self->{_io}->read_u1();
    $self->{radial} = $self->{_io}->read_s4le();
    $self->{along} = $self->{_io}->read_s4le();
    $self->{cross} = $self->{_io}->read_s4le();
    $self->{dot_radial} = $self->{_io}->read_s4le();
    $self->{dot_along} = $self->{_io}->read_s4le();
    $self->{dot_cross} = $self->{_io}->read_s4le();
    $self->{c0} = $self->{_io}->read_s4le();
    $self->{c1} = $self->{_io}->read_s4le();
    $self->{c2} = $self->{_io}->read_s4le();
}

sub time {
    my ($self) = @_;
    return $self->{time};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub update_interval {
    my ($self) = @_;
    return $self->{update_interval};
}

sub iod_ssr {
    my ($self) = @_;
    return $self->{iod_ssr};
}

sub iod {
    my ($self) = @_;
    return $self->{iod};
}

sub radial {
    my ($self) = @_;
    return $self->{radial};
}

sub along {
    my ($self) = @_;
    return $self->{along};
}

sub cross {
    my ($self) = @_;
    return $self->{cross};
}

sub dot_radial {
    my ($self) = @_;
    return $self->{dot_radial};
}

sub dot_along {
    my ($self) = @_;
    return $self->{dot_along};
}

sub dot_cross {
    my ($self) = @_;
    return $self->{dot_cross};
}

sub c0 {
    my ($self) = @_;
    return $self->{c0};
}

sub c1 {
    my ($self) = @_;
    return $self->{c1};
}

sub c2 {
    my ($self) = @_;
    return $self->{c2};
}

########################################################################
package Ssr::MsgSsrStecCorrection;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{header} = Ssr::BoundsHeader->new($self->{_io}, $self, $self->{_root});
    $self->{ssr_iod_atmo} = $self->{_io}->read_u1();
    $self->{tile_set_id} = $self->{_io}->read_u2le();
    $self->{tile_id} = $self->{_io}->read_u2le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{stec_sat_list} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{stec_sat_list}}, Ssr::StecSatElement->new($self->{_io}, $self, $self->{_root});
    }
}

sub header {
    my ($self) = @_;
    return $self->{header};
}

sub ssr_iod_atmo {
    my ($self) = @_;
    return $self->{ssr_iod_atmo};
}

sub tile_set_id {
    my ($self) = @_;
    return $self->{tile_set_id};
}

sub tile_id {
    my ($self) = @_;
    return $self->{tile_id};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub stec_sat_list {
    my ($self) = @_;
    return $self->{stec_sat_list};
}

########################################################################
package Ssr::MsgSsrOrbitClock;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{time} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{sid} = Gnss::GnssSignal->new($self->{_io}, $self, $self->{_root});
    $self->{update_interval} = $self->{_io}->read_u1();
    $self->{iod_ssr} = $self->{_io}->read_u1();
    $self->{iod} = $self->{_io}->read_u4le();
    $self->{radial} = $self->{_io}->read_s4le();
    $self->{along} = $self->{_io}->read_s4le();
    $self->{cross} = $self->{_io}->read_s4le();
    $self->{dot_radial} = $self->{_io}->read_s4le();
    $self->{dot_along} = $self->{_io}->read_s4le();
    $self->{dot_cross} = $self->{_io}->read_s4le();
    $self->{c0} = $self->{_io}->read_s4le();
    $self->{c1} = $self->{_io}->read_s4le();
    $self->{c2} = $self->{_io}->read_s4le();
}

sub time {
    my ($self) = @_;
    return $self->{time};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub update_interval {
    my ($self) = @_;
    return $self->{update_interval};
}

sub iod_ssr {
    my ($self) = @_;
    return $self->{iod_ssr};
}

sub iod {
    my ($self) = @_;
    return $self->{iod};
}

sub radial {
    my ($self) = @_;
    return $self->{radial};
}

sub along {
    my ($self) = @_;
    return $self->{along};
}

sub cross {
    my ($self) = @_;
    return $self->{cross};
}

sub dot_radial {
    my ($self) = @_;
    return $self->{dot_radial};
}

sub dot_along {
    my ($self) = @_;
    return $self->{dot_along};
}

sub dot_cross {
    my ($self) = @_;
    return $self->{dot_cross};
}

sub c0 {
    my ($self) = @_;
    return $self->{c0};
}

sub c1 {
    my ($self) = @_;
    return $self->{c1};
}

sub c2 {
    my ($self) = @_;
    return $self->{c2};
}

########################################################################
package Ssr::BoundsHeader;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{time} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{num_msgs} = $self->{_io}->read_u1();
    $self->{seq_num} = $self->{_io}->read_u1();
    $self->{update_interval} = $self->{_io}->read_u1();
    $self->{sol_id} = $self->{_io}->read_u1();
}

sub time {
    my ($self) = @_;
    return $self->{time};
}

sub num_msgs {
    my ($self) = @_;
    return $self->{num_msgs};
}

sub seq_num {
    my ($self) = @_;
    return $self->{seq_num};
}

sub update_interval {
    my ($self) = @_;
    return $self->{update_interval};
}

sub sol_id {
    my ($self) = @_;
    return $self->{sol_id};
}

########################################################################
package Ssr::MsgSsrGriddedCorrection;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{header} = Ssr::GriddedCorrectionHeader->new($self->{_io}, $self, $self->{_root});
    $self->{index} = $self->{_io}->read_u2le();
    $self->{tropo_delay_correction} = Ssr::TroposphericDelayCorrection->new($self->{_io}, $self, $self->{_root});
    $self->{stec_residuals} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{stec_residuals}}, Ssr::StecResidual->new($self->{_io}, $self, $self->{_root});
    }
}

sub header {
    my ($self) = @_;
    return $self->{header};
}

sub index {
    my ($self) = @_;
    return $self->{index};
}

sub tropo_delay_correction {
    my ($self) = @_;
    return $self->{tropo_delay_correction};
}

sub stec_residuals {
    my ($self) = @_;
    return $self->{stec_residuals};
}

########################################################################
package Ssr::StecResidual;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{sv_id} = Gnss::SvId->new($self->{_io}, $self, $self->{_root});
    $self->{residual} = $self->{_io}->read_s2le();
    $self->{stddev} = $self->{_io}->read_u1();
}

sub sv_id {
    my ($self) = @_;
    return $self->{sv_id};
}

sub residual {
    my ($self) = @_;
    return $self->{residual};
}

sub stddev {
    my ($self) = @_;
    return $self->{stddev};
}

########################################################################
package Ssr::CodePhaseBiasesSatSig;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{sat_id} = $self->{_io}->read_u1();
    $self->{signal_id} = $self->{_io}->read_u1();
    $self->{code_bias_bound_mu} = $self->{_io}->read_u1();
    $self->{code_bias_bound_sig} = $self->{_io}->read_u1();
    $self->{phase_bias_bound_mu} = $self->{_io}->read_u1();
    $self->{phase_bias_bound_sig} = $self->{_io}->read_u1();
}

sub sat_id {
    my ($self) = @_;
    return $self->{sat_id};
}

sub signal_id {
    my ($self) = @_;
    return $self->{signal_id};
}

sub code_bias_bound_mu {
    my ($self) = @_;
    return $self->{code_bias_bound_mu};
}

sub code_bias_bound_sig {
    my ($self) = @_;
    return $self->{code_bias_bound_sig};
}

sub phase_bias_bound_mu {
    my ($self) = @_;
    return $self->{phase_bias_bound_mu};
}

sub phase_bias_bound_sig {
    my ($self) = @_;
    return $self->{phase_bias_bound_sig};
}

########################################################################
package Ssr::SatelliteApc;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{sid} = Gnss::GnssSignal->new($self->{_io}, $self, $self->{_root});
    $self->{sat_info} = $self->{_io}->read_u1();
    $self->{svn} = $self->{_io}->read_u2le();
    $self->{pco} = [];
    my $n_pco = 3;
    for (my $i = 0; $i < $n_pco; $i++) {
        push @{$self->{pco}}, $self->{_io}->read_s2le();
    }
    $self->{pcv} = [];
    my $n_pcv = 21;
    for (my $i = 0; $i < $n_pcv; $i++) {
        push @{$self->{pcv}}, $self->{_io}->read_s1();
    }
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub sat_info {
    my ($self) = @_;
    return $self->{sat_info};
}

sub svn {
    my ($self) = @_;
    return $self->{svn};
}

sub pco {
    my ($self) = @_;
    return $self->{pco};
}

sub pcv {
    my ($self) = @_;
    return $self->{pcv};
}

########################################################################
package Ssr::GriddedCorrectionHeader;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{tile_set_id} = $self->{_io}->read_u2le();
    $self->{tile_id} = $self->{_io}->read_u2le();
    $self->{time} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{num_msgs} = $self->{_io}->read_u2le();
    $self->{seq_num} = $self->{_io}->read_u2le();
    $self->{update_interval} = $self->{_io}->read_u1();
    $self->{iod_atmo} = $self->{_io}->read_u1();
    $self->{tropo_quality_indicator} = $self->{_io}->read_u1();
}

sub tile_set_id {
    my ($self) = @_;
    return $self->{tile_set_id};
}

sub tile_id {
    my ($self) = @_;
    return $self->{tile_id};
}

sub time {
    my ($self) = @_;
    return $self->{time};
}

sub num_msgs {
    my ($self) = @_;
    return $self->{num_msgs};
}

sub seq_num {
    my ($self) = @_;
    return $self->{seq_num};
}

sub update_interval {
    my ($self) = @_;
    return $self->{update_interval};
}

sub iod_atmo {
    my ($self) = @_;
    return $self->{iod_atmo};
}

sub tropo_quality_indicator {
    my ($self) = @_;
    return $self->{tropo_quality_indicator};
}

########################################################################
package Ssr::StecSatElement;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{sv_id} = Gnss::SvId->new($self->{_io}, $self, $self->{_root});
    $self->{stec_quality_indicator} = $self->{_io}->read_u1();
    $self->{stec_coeff} = [];
    my $n_stec_coeff = 4;
    for (my $i = 0; $i < $n_stec_coeff; $i++) {
        push @{$self->{stec_coeff}}, $self->{_io}->read_s2le();
    }
}

sub sv_id {
    my ($self) = @_;
    return $self->{sv_id};
}

sub stec_quality_indicator {
    my ($self) = @_;
    return $self->{stec_quality_indicator};
}

sub stec_coeff {
    my ($self) = @_;
    return $self->{stec_coeff};
}

########################################################################
package Ssr::StecHeaderDepA;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{time} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{num_msgs} = $self->{_io}->read_u1();
    $self->{seq_num} = $self->{_io}->read_u1();
    $self->{update_interval} = $self->{_io}->read_u1();
    $self->{iod_atmo} = $self->{_io}->read_u1();
}

sub time {
    my ($self) = @_;
    return $self->{time};
}

sub num_msgs {
    my ($self) = @_;
    return $self->{num_msgs};
}

sub seq_num {
    my ($self) = @_;
    return $self->{seq_num};
}

sub update_interval {
    my ($self) = @_;
    return $self->{update_interval};
}

sub iod_atmo {
    my ($self) = @_;
    return $self->{iod_atmo};
}

########################################################################
package Ssr::StecHeader;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{tile_set_id} = $self->{_io}->read_u2le();
    $self->{tile_id} = $self->{_io}->read_u2le();
    $self->{time} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{num_msgs} = $self->{_io}->read_u1();
    $self->{seq_num} = $self->{_io}->read_u1();
    $self->{update_interval} = $self->{_io}->read_u1();
    $self->{iod_atmo} = $self->{_io}->read_u1();
}

sub tile_set_id {
    my ($self) = @_;
    return $self->{tile_set_id};
}

sub tile_id {
    my ($self) = @_;
    return $self->{tile_id};
}

sub time {
    my ($self) = @_;
    return $self->{time};
}

sub num_msgs {
    my ($self) = @_;
    return $self->{num_msgs};
}

sub seq_num {
    my ($self) = @_;
    return $self->{seq_num};
}

sub update_interval {
    my ($self) = @_;
    return $self->{update_interval};
}

sub iod_atmo {
    my ($self) = @_;
    return $self->{iod_atmo};
}

########################################################################
package Ssr::MsgSsrStecCorrectionDepA;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{header} = Ssr::StecHeaderDepA->new($self->{_io}, $self, $self->{_root});
    $self->{stec_sat_list} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{stec_sat_list}}, Ssr::StecSatElement->new($self->{_io}, $self, $self->{_root});
    }
}

sub header {
    my ($self) = @_;
    return $self->{header};
}

sub stec_sat_list {
    my ($self) = @_;
    return $self->{stec_sat_list};
}

########################################################################
package Ssr::GriddedCorrectionHeaderDepA;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{time} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{num_msgs} = $self->{_io}->read_u2le();
    $self->{seq_num} = $self->{_io}->read_u2le();
    $self->{update_interval} = $self->{_io}->read_u1();
    $self->{iod_atmo} = $self->{_io}->read_u1();
    $self->{tropo_quality_indicator} = $self->{_io}->read_u1();
}

sub time {
    my ($self) = @_;
    return $self->{time};
}

sub num_msgs {
    my ($self) = @_;
    return $self->{num_msgs};
}

sub seq_num {
    my ($self) = @_;
    return $self->{seq_num};
}

sub update_interval {
    my ($self) = @_;
    return $self->{update_interval};
}

sub iod_atmo {
    my ($self) = @_;
    return $self->{iod_atmo};
}

sub tropo_quality_indicator {
    my ($self) = @_;
    return $self->{tropo_quality_indicator};
}

########################################################################
package Ssr::MsgSsrOrbitClockBounds;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{header} = Ssr::BoundsHeader->new($self->{_io}, $self, $self->{_root});
    $self->{ssr_iod} = $self->{_io}->read_u1();
    $self->{const_id} = $self->{_io}->read_u1();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{orbit_clock_bounds} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{orbit_clock_bounds}}, Ssr::OrbitClockBound->new($self->{_io}, $self, $self->{_root});
    }
}

sub header {
    my ($self) = @_;
    return $self->{header};
}

sub ssr_iod {
    my ($self) = @_;
    return $self->{ssr_iod};
}

sub const_id {
    my ($self) = @_;
    return $self->{const_id};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub orbit_clock_bounds {
    my ($self) = @_;
    return $self->{orbit_clock_bounds};
}

########################################################################
package Ssr::MsgSsrGriddedCorrectionBounds;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{header} = Ssr::BoundsHeader->new($self->{_io}, $self, $self->{_root});
    $self->{ssr_iod_atmo} = $self->{_io}->read_u1();
    $self->{tile_set_id} = $self->{_io}->read_u2le();
    $self->{tile_id} = $self->{_io}->read_u2le();
    $self->{tropo_qi} = $self->{_io}->read_u1();
    $self->{grid_point_id} = $self->{_io}->read_u2le();
    $self->{tropo_delay_correction} = Ssr::TroposphericDelayCorrection->new($self->{_io}, $self, $self->{_root});
    $self->{tropo_v_hydro_bound_mu} = $self->{_io}->read_u1();
    $self->{tropo_v_hydro_bound_sig} = $self->{_io}->read_u1();
    $self->{tropo_v_wet_bound_mu} = $self->{_io}->read_u1();
    $self->{tropo_v_wet_bound_sig} = $self->{_io}->read_u1();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{stec_sat_list} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{stec_sat_list}}, Ssr::StecSatElementIntegrity->new($self->{_io}, $self, $self->{_root});
    }
}

sub header {
    my ($self) = @_;
    return $self->{header};
}

sub ssr_iod_atmo {
    my ($self) = @_;
    return $self->{ssr_iod_atmo};
}

sub tile_set_id {
    my ($self) = @_;
    return $self->{tile_set_id};
}

sub tile_id {
    my ($self) = @_;
    return $self->{tile_id};
}

sub tropo_qi {
    my ($self) = @_;
    return $self->{tropo_qi};
}

sub grid_point_id {
    my ($self) = @_;
    return $self->{grid_point_id};
}

sub tropo_delay_correction {
    my ($self) = @_;
    return $self->{tropo_delay_correction};
}

sub tropo_v_hydro_bound_mu {
    my ($self) = @_;
    return $self->{tropo_v_hydro_bound_mu};
}

sub tropo_v_hydro_bound_sig {
    my ($self) = @_;
    return $self->{tropo_v_hydro_bound_sig};
}

sub tropo_v_wet_bound_mu {
    my ($self) = @_;
    return $self->{tropo_v_wet_bound_mu};
}

sub tropo_v_wet_bound_sig {
    my ($self) = @_;
    return $self->{tropo_v_wet_bound_sig};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub stec_sat_list {
    my ($self) = @_;
    return $self->{stec_sat_list};
}

########################################################################
package Ssr::MsgSsrGridDefinitionDepA;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{header} = Ssr::GridDefinitionHeaderDepA->new($self->{_io}, $self, $self->{_root});
    $self->{rle_list} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{rle_list}}, $self->{_io}->read_u1();
    }
}

sub header {
    my ($self) = @_;
    return $self->{header};
}

sub rle_list {
    my ($self) = @_;
    return $self->{rle_list};
}

########################################################################
package Ssr::CodeBiasesContent;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{code} = $self->{_io}->read_u1();
    $self->{value} = $self->{_io}->read_s2le();
}

sub code {
    my ($self) = @_;
    return $self->{code};
}

sub value {
    my ($self) = @_;
    return $self->{value};
}

########################################################################
package Ssr::MsgSsrSatelliteApc;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{time} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{update_interval} = $self->{_io}->read_u1();
    $self->{sol_id} = $self->{_io}->read_u1();
    $self->{iod_ssr} = $self->{_io}->read_u1();
    $self->{apc} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{apc}}, Ssr::SatelliteApc->new($self->{_io}, $self, $self->{_root});
    }
}

sub time {
    my ($self) = @_;
    return $self->{time};
}

sub update_interval {
    my ($self) = @_;
    return $self->{update_interval};
}

sub sol_id {
    my ($self) = @_;
    return $self->{sol_id};
}

sub iod_ssr {
    my ($self) = @_;
    return $self->{iod_ssr};
}

sub apc {
    my ($self) = @_;
    return $self->{apc};
}

########################################################################
package Ssr::PhaseBiasesContent;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{code} = $self->{_io}->read_u1();
    $self->{integer_indicator} = $self->{_io}->read_u1();
    $self->{widelane_integer_indicator} = $self->{_io}->read_u1();
    $self->{discontinuity_counter} = $self->{_io}->read_u1();
    $self->{bias} = $self->{_io}->read_s4le();
}

sub code {
    my ($self) = @_;
    return $self->{code};
}

sub integer_indicator {
    my ($self) = @_;
    return $self->{integer_indicator};
}

sub widelane_integer_indicator {
    my ($self) = @_;
    return $self->{widelane_integer_indicator};
}

sub discontinuity_counter {
    my ($self) = @_;
    return $self->{discontinuity_counter};
}

sub bias {
    my ($self) = @_;
    return $self->{bias};
}

########################################################################
package Ssr::MsgSsrTileDefinitionDepA;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{tile_set_id} = $self->{_io}->read_u2le();
    $self->{tile_id} = $self->{_io}->read_u2le();
    $self->{corner_nw_lat} = $self->{_io}->read_s2le();
    $self->{corner_nw_lon} = $self->{_io}->read_s2le();
    $self->{spacing_lat} = $self->{_io}->read_u2le();
    $self->{spacing_lon} = $self->{_io}->read_u2le();
    $self->{rows} = $self->{_io}->read_u2le();
    $self->{cols} = $self->{_io}->read_u2le();
    $self->{bitmask} = $self->{_io}->read_u8le();
}

sub tile_set_id {
    my ($self) = @_;
    return $self->{tile_set_id};
}

sub tile_id {
    my ($self) = @_;
    return $self->{tile_id};
}

sub corner_nw_lat {
    my ($self) = @_;
    return $self->{corner_nw_lat};
}

sub corner_nw_lon {
    my ($self) = @_;
    return $self->{corner_nw_lon};
}

sub spacing_lat {
    my ($self) = @_;
    return $self->{spacing_lat};
}

sub spacing_lon {
    my ($self) = @_;
    return $self->{spacing_lon};
}

sub rows {
    my ($self) = @_;
    return $self->{rows};
}

sub cols {
    my ($self) = @_;
    return $self->{cols};
}

sub bitmask {
    my ($self) = @_;
    return $self->{bitmask};
}

########################################################################
package Ssr::OrbitClockBound;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{sat_id} = $self->{_io}->read_u1();
    $self->{orb_radial_bound_mu} = $self->{_io}->read_u1();
    $self->{orb_along_bound_mu} = $self->{_io}->read_u1();
    $self->{orb_cross_bound_mu} = $self->{_io}->read_u1();
    $self->{orb_radial_bound_sig} = $self->{_io}->read_u1();
    $self->{orb_along_bound_sig} = $self->{_io}->read_u1();
    $self->{orb_cross_bound_sig} = $self->{_io}->read_u1();
    $self->{clock_bound_mu} = $self->{_io}->read_u1();
    $self->{clock_bound_sig} = $self->{_io}->read_u1();
}

sub sat_id {
    my ($self) = @_;
    return $self->{sat_id};
}

sub orb_radial_bound_mu {
    my ($self) = @_;
    return $self->{orb_radial_bound_mu};
}

sub orb_along_bound_mu {
    my ($self) = @_;
    return $self->{orb_along_bound_mu};
}

sub orb_cross_bound_mu {
    my ($self) = @_;
    return $self->{orb_cross_bound_mu};
}

sub orb_radial_bound_sig {
    my ($self) = @_;
    return $self->{orb_radial_bound_sig};
}

sub orb_along_bound_sig {
    my ($self) = @_;
    return $self->{orb_along_bound_sig};
}

sub orb_cross_bound_sig {
    my ($self) = @_;
    return $self->{orb_cross_bound_sig};
}

sub clock_bound_mu {
    my ($self) = @_;
    return $self->{clock_bound_mu};
}

sub clock_bound_sig {
    my ($self) = @_;
    return $self->{clock_bound_sig};
}

########################################################################
package Ssr::MsgSsrGriddedCorrectionDepA;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{header} = Ssr::GriddedCorrectionHeaderDepA->new($self->{_io}, $self, $self->{_root});
    $self->{index} = $self->{_io}->read_u2le();
    $self->{tropo_delay_correction} = Ssr::TroposphericDelayCorrection->new($self->{_io}, $self, $self->{_root});
    $self->{stec_residuals} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{stec_residuals}}, Ssr::StecResidual->new($self->{_io}, $self, $self->{_root});
    }
}

sub header {
    my ($self) = @_;
    return $self->{header};
}

sub index {
    my ($self) = @_;
    return $self->{index};
}

sub tropo_delay_correction {
    my ($self) = @_;
    return $self->{tropo_delay_correction};
}

sub stec_residuals {
    my ($self) = @_;
    return $self->{stec_residuals};
}

########################################################################
package Ssr::MsgSsrOrbitClockBoundsDegradation;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{header} = Ssr::BoundsHeader->new($self->{_io}, $self, $self->{_root});
    $self->{ssr_iod} = $self->{_io}->read_u1();
    $self->{const_id} = $self->{_io}->read_u1();
    $self->{sat_bitmask} = $self->{_io}->read_u8le();
    $self->{orbit_clock_bounds_degradation} = Ssr::OrbitClockBoundDegradation->new($self->{_io}, $self, $self->{_root});
}

sub header {
    my ($self) = @_;
    return $self->{header};
}

sub ssr_iod {
    my ($self) = @_;
    return $self->{ssr_iod};
}

sub const_id {
    my ($self) = @_;
    return $self->{const_id};
}

sub sat_bitmask {
    my ($self) = @_;
    return $self->{sat_bitmask};
}

sub orbit_clock_bounds_degradation {
    my ($self) = @_;
    return $self->{orbit_clock_bounds_degradation};
}

########################################################################
package Ssr::MsgSsrGriddedCorrectionNoStdDepA;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{header} = Ssr::GriddedCorrectionHeaderDepA->new($self->{_io}, $self, $self->{_root});
    $self->{index} = $self->{_io}->read_u2le();
    $self->{tropo_delay_correction} = Ssr::TroposphericDelayCorrectionNoStd->new($self->{_io}, $self, $self->{_root});
    $self->{stec_residuals} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{stec_residuals}}, Ssr::StecResidualNoStd->new($self->{_io}, $self, $self->{_root});
    }
}

sub header {
    my ($self) = @_;
    return $self->{header};
}

sub index {
    my ($self) = @_;
    return $self->{index};
}

sub tropo_delay_correction {
    my ($self) = @_;
    return $self->{tropo_delay_correction};
}

sub stec_residuals {
    my ($self) = @_;
    return $self->{stec_residuals};
}

########################################################################
package Ssr::MsgSsrCodePhaseBiasesBounds;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{header} = Ssr::BoundsHeader->new($self->{_io}, $self, $self->{_root});
    $self->{ssr_iod} = $self->{_io}->read_u1();
    $self->{const_id} = $self->{_io}->read_u1();
    $self->{n_sats_signals} = $self->{_io}->read_u1();
    $self->{satellites_signals} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{satellites_signals}}, Ssr::CodePhaseBiasesSatSig->new($self->{_io}, $self, $self->{_root});
    }
}

sub header {
    my ($self) = @_;
    return $self->{header};
}

sub ssr_iod {
    my ($self) = @_;
    return $self->{ssr_iod};
}

sub const_id {
    my ($self) = @_;
    return $self->{const_id};
}

sub n_sats_signals {
    my ($self) = @_;
    return $self->{n_sats_signals};
}

sub satellites_signals {
    my ($self) = @_;
    return $self->{satellites_signals};
}

########################################################################
package Ssr::MsgSsrCodeBiases;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{time} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{sid} = Gnss::GnssSignal->new($self->{_io}, $self, $self->{_root});
    $self->{update_interval} = $self->{_io}->read_u1();
    $self->{iod_ssr} = $self->{_io}->read_u1();
    $self->{biases} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{biases}}, Ssr::CodeBiasesContent->new($self->{_io}, $self, $self->{_root});
    }
}

sub time {
    my ($self) = @_;
    return $self->{time};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub update_interval {
    my ($self) = @_;
    return $self->{update_interval};
}

sub iod_ssr {
    my ($self) = @_;
    return $self->{iod_ssr};
}

sub biases {
    my ($self) = @_;
    return $self->{biases};
}

########################################################################
package Ssr::MsgSsrTileDefinition;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{time} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{update_interval} = $self->{_io}->read_u1();
    $self->{sol_id} = $self->{_io}->read_u1();
    $self->{iod_atmo} = $self->{_io}->read_u1();
    $self->{tile_set_id} = $self->{_io}->read_u2le();
    $self->{tile_id} = $self->{_io}->read_u2le();
    $self->{corner_nw_lat} = $self->{_io}->read_s2le();
    $self->{corner_nw_lon} = $self->{_io}->read_s2le();
    $self->{spacing_lat} = $self->{_io}->read_u2le();
    $self->{spacing_lon} = $self->{_io}->read_u2le();
    $self->{rows} = $self->{_io}->read_u2le();
    $self->{cols} = $self->{_io}->read_u2le();
    $self->{bitmask} = $self->{_io}->read_u8le();
}

sub time {
    my ($self) = @_;
    return $self->{time};
}

sub update_interval {
    my ($self) = @_;
    return $self->{update_interval};
}

sub sol_id {
    my ($self) = @_;
    return $self->{sol_id};
}

sub iod_atmo {
    my ($self) = @_;
    return $self->{iod_atmo};
}

sub tile_set_id {
    my ($self) = @_;
    return $self->{tile_set_id};
}

sub tile_id {
    my ($self) = @_;
    return $self->{tile_id};
}

sub corner_nw_lat {
    my ($self) = @_;
    return $self->{corner_nw_lat};
}

sub corner_nw_lon {
    my ($self) = @_;
    return $self->{corner_nw_lon};
}

sub spacing_lat {
    my ($self) = @_;
    return $self->{spacing_lat};
}

sub spacing_lon {
    my ($self) = @_;
    return $self->{spacing_lon};
}

sub rows {
    my ($self) = @_;
    return $self->{rows};
}

sub cols {
    my ($self) = @_;
    return $self->{cols};
}

sub bitmask {
    my ($self) = @_;
    return $self->{bitmask};
}

########################################################################
package Ssr::OrbitClockBoundDegradation;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{orb_radial_bound_mu_dot} = $self->{_io}->read_u1();
    $self->{orb_along_bound_mu_dot} = $self->{_io}->read_u1();
    $self->{orb_cross_bound_mu_dot} = $self->{_io}->read_u1();
    $self->{orb_radial_bound_sig_dot} = $self->{_io}->read_u1();
    $self->{orb_along_bound_sig_dot} = $self->{_io}->read_u1();
    $self->{orb_cross_bound_sig_dot} = $self->{_io}->read_u1();
    $self->{clock_bound_mu_dot} = $self->{_io}->read_u1();
    $self->{clock_bound_sig_dot} = $self->{_io}->read_u1();
}

sub orb_radial_bound_mu_dot {
    my ($self) = @_;
    return $self->{orb_radial_bound_mu_dot};
}

sub orb_along_bound_mu_dot {
    my ($self) = @_;
    return $self->{orb_along_bound_mu_dot};
}

sub orb_cross_bound_mu_dot {
    my ($self) = @_;
    return $self->{orb_cross_bound_mu_dot};
}

sub orb_radial_bound_sig_dot {
    my ($self) = @_;
    return $self->{orb_radial_bound_sig_dot};
}

sub orb_along_bound_sig_dot {
    my ($self) = @_;
    return $self->{orb_along_bound_sig_dot};
}

sub orb_cross_bound_sig_dot {
    my ($self) = @_;
    return $self->{orb_cross_bound_sig_dot};
}

sub clock_bound_mu_dot {
    my ($self) = @_;
    return $self->{clock_bound_mu_dot};
}

sub clock_bound_sig_dot {
    my ($self) = @_;
    return $self->{clock_bound_sig_dot};
}

########################################################################
package Ssr::MsgSsrSatelliteApcDep;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{apc} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{apc}}, Ssr::SatelliteApc->new($self->{_io}, $self, $self->{_root});
    }
}

sub apc {
    my ($self) = @_;
    return $self->{apc};
}

########################################################################
package Ssr::TroposphericDelayCorrection;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{hydro} = $self->{_io}->read_s2le();
    $self->{wet} = $self->{_io}->read_s1();
    $self->{stddev} = $self->{_io}->read_u1();
}

sub hydro {
    my ($self) = @_;
    return $self->{hydro};
}

sub wet {
    my ($self) = @_;
    return $self->{wet};
}

sub stddev {
    my ($self) = @_;
    return $self->{stddev};
}

########################################################################
package Ssr::MsgSsrTileDefinitionDepB;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{ssr_sol_id} = $self->{_io}->read_u1();
    $self->{tile_set_id} = $self->{_io}->read_u2le();
    $self->{tile_id} = $self->{_io}->read_u2le();
    $self->{corner_nw_lat} = $self->{_io}->read_s2le();
    $self->{corner_nw_lon} = $self->{_io}->read_s2le();
    $self->{spacing_lat} = $self->{_io}->read_u2le();
    $self->{spacing_lon} = $self->{_io}->read_u2le();
    $self->{rows} = $self->{_io}->read_u2le();
    $self->{cols} = $self->{_io}->read_u2le();
    $self->{bitmask} = $self->{_io}->read_u8le();
}

sub ssr_sol_id {
    my ($self) = @_;
    return $self->{ssr_sol_id};
}

sub tile_set_id {
    my ($self) = @_;
    return $self->{tile_set_id};
}

sub tile_id {
    my ($self) = @_;
    return $self->{tile_id};
}

sub corner_nw_lat {
    my ($self) = @_;
    return $self->{corner_nw_lat};
}

sub corner_nw_lon {
    my ($self) = @_;
    return $self->{corner_nw_lon};
}

sub spacing_lat {
    my ($self) = @_;
    return $self->{spacing_lat};
}

sub spacing_lon {
    my ($self) = @_;
    return $self->{spacing_lon};
}

sub rows {
    my ($self) = @_;
    return $self->{rows};
}

sub cols {
    my ($self) = @_;
    return $self->{cols};
}

sub bitmask {
    my ($self) = @_;
    return $self->{bitmask};
}

########################################################################
package Ssr::MsgSsrPhaseBiases;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{time} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{sid} = Gnss::GnssSignal->new($self->{_io}, $self, $self->{_root});
    $self->{update_interval} = $self->{_io}->read_u1();
    $self->{iod_ssr} = $self->{_io}->read_u1();
    $self->{dispersive_bias} = $self->{_io}->read_u1();
    $self->{mw_consistency} = $self->{_io}->read_u1();
    $self->{yaw} = $self->{_io}->read_u2le();
    $self->{yaw_rate} = $self->{_io}->read_s1();
    $self->{biases} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{biases}}, Ssr::PhaseBiasesContent->new($self->{_io}, $self, $self->{_root});
    }
}

sub time {
    my ($self) = @_;
    return $self->{time};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub update_interval {
    my ($self) = @_;
    return $self->{update_interval};
}

sub iod_ssr {
    my ($self) = @_;
    return $self->{iod_ssr};
}

sub dispersive_bias {
    my ($self) = @_;
    return $self->{dispersive_bias};
}

sub mw_consistency {
    my ($self) = @_;
    return $self->{mw_consistency};
}

sub yaw {
    my ($self) = @_;
    return $self->{yaw};
}

sub yaw_rate {
    my ($self) = @_;
    return $self->{yaw_rate};
}

sub biases {
    my ($self) = @_;
    return $self->{biases};
}

1;
