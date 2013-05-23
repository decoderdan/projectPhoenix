  


<!DOCTYPE html>
<html>
  <head prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb# githubog: http://ogp.me/ns/fb/githubog#">
    <meta charset='utf-8'>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>projectChimaera/Drivers/vNavIMU/src/vncp_services.c at master · alexsleat/projectChimaera</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub" />
    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub" />
    <link rel="apple-touch-icon" sizes="57x57" href="/apple-touch-icon-114.png" />
    <link rel="apple-touch-icon" sizes="114x114" href="/apple-touch-icon-114.png" />
    <link rel="apple-touch-icon" sizes="72x72" href="/apple-touch-icon-144.png" />
    <link rel="apple-touch-icon" sizes="144x144" href="/apple-touch-icon-144.png" />
    <link rel="logo" type="image/svg" href="http://github-media-downloads.s3.amazonaws.com/github-logo.svg" />
    <link rel="xhr-socket" href="/_sockets" />


    <meta name="msapplication-TileImage" content="/windows-tile.png" />
    <meta name="msapplication-TileColor" content="#ffffff" />
    <meta name="selected-link" value="repo_source" data-pjax-transient />
    <meta content="collector.githubapp.com" name="octolytics-host" /><meta content="github" name="octolytics-app-id" /><meta content="4387844" name="octolytics-actor-id" /><meta content="6724fef95ca66b1721a48fc3380a0f98824bd983c9188c66585a304e1c2c3abb" name="octolytics-actor-hash" />

    
    
    <link rel="icon" type="image/x-icon" href="/favicon.ico" />

    <meta content="authenticity_token" name="csrf-param" />
<meta content="E/J5yMbdx1u/0AjbIXscdtgDWlF6wTc5JrXKQJCYF2M=" name="csrf-token" />

    <link href="https://a248.e.akamai.net/assets.github.com/assets/github-fdebe8d3f60746fb87c763a59741ff520ae3d8e8.css" media="all" rel="stylesheet" type="text/css" />
    <link href="https://a248.e.akamai.net/assets.github.com/assets/github2-d530e63e2c132c7f0e6ac7228e7e1ab9ef2a8d94.css" media="all" rel="stylesheet" type="text/css" />
    


      <script src="https://a248.e.akamai.net/assets.github.com/assets/frameworks-92d138f450f2960501e28397a2f63b0f100590f0.js" type="text/javascript"></script>
      <script src="https://a248.e.akamai.net/assets.github.com/assets/github-4037f12703c2d563310be4fcd52a229189468cce.js" type="text/javascript"></script>
      
      <meta http-equiv="x-pjax-version" content="80973bfd2a5cb09c53d745b26b5b1dc0">

        <link data-pjax-transient rel='permalink' href='/alexsleat/projectChimaera/blob/636edcda74a3a158bf88efae8b7814645184a1b3/Drivers/vNavIMU/src/vncp_services.c'>
    <meta property="og:title" content="projectChimaera"/>
    <meta property="og:type" content="githubog:gitrepository"/>
    <meta property="og:url" content="https://github.com/alexsleat/projectChimaera"/>
    <meta property="og:image" content="https://secure.gravatar.com/avatar/927d325c2b7f43176703521bcf18ea60?s=420&amp;d=https://a248.e.akamai.net/assets.github.com%2Fimages%2Fgravatars%2Fgravatar-user-420.png"/>
    <meta property="og:site_name" content="GitHub"/>
    <meta property="og:description" content="projectChimaera - Rinzler is an exceptionally skilled warrior and is the elite combatant in all games in the Grid."/>
    <meta property="twitter:card" content="summary"/>
    <meta property="twitter:site" content="@GitHub">
    <meta property="twitter:title" content="alexsleat/projectChimaera"/>

    <meta name="description" content="projectChimaera - Rinzler is an exceptionally skilled warrior and is the elite combatant in all games in the Grid." />


    <meta content="305784" name="octolytics-dimension-user_id" /><meta content="2822251" name="octolytics-dimension-repository_id" />
  <link href="https://github.com/alexsleat/projectChimaera/commits/master.atom" rel="alternate" title="Recent Commits to projectChimaera:master" type="application/atom+xml" />

  </head>


  <body class="logged_in page-blob linux vis-public fork env-production  ">
    <div id="wrapper">

      

      
      
      

      <div class="header header-logged-in true">
  <div class="container clearfix">

    <a class="header-logo-invertocat" href="https://github.com/">
  <span class="mega-icon mega-icon-invertocat"></span>
</a>

    <div class="divider-vertical"></div>

      <a href="/notifications" class="notification-indicator tooltipped downwards" title="You have no unread notifications">
    <span class="mail-status all-read"></span>
  </a>
  <div class="divider-vertical"></div>


      <div class="command-bar js-command-bar  in-repository">
          <form accept-charset="UTF-8" action="/search" class="command-bar-form" id="top_search_form" method="get">
  <a href="/search/advanced" class="advanced-search-icon tooltipped downwards command-bar-search" id="advanced_search" title="Advanced search"><span class="mini-icon mini-icon-advanced-search "></span></a>

  <input type="text" data-hotkey="/ s" name="q" id="js-command-bar-field" placeholder="Search or type a command" tabindex="1" autocapitalize="off"
    data-username="matthuxford"
      data-repo="alexsleat/projectChimaera"
      data-branch="master"
      data-sha="fb648041dc514e860e9140c35e4957488ffdfd31"
  >

    <input type="hidden" name="nwo" value="alexsleat/projectChimaera" />

    <div class="select-menu js-menu-container js-select-menu search-context-select-menu">
      <span class="minibutton select-menu-button js-menu-target">
        <span class="js-select-button">This repository</span>
      </span>

      <div class="select-menu-modal-holder js-menu-content js-navigation-container">
        <div class="select-menu-modal">

          <div class="select-menu-item js-navigation-item selected">
            <span class="select-menu-item-icon mini-icon mini-icon-confirm"></span>
            <input type="radio" class="js-search-this-repository" name="search_target" value="repository" checked="checked" />
            <div class="select-menu-item-text js-select-button-text">This repository</div>
          </div> <!-- /.select-menu-item -->

          <div class="select-menu-item js-navigation-item">
            <span class="select-menu-item-icon mini-icon mini-icon-confirm"></span>
            <input type="radio" name="search_target" value="global" />
            <div class="select-menu-item-text js-select-button-text">All repositories</div>
          </div> <!-- /.select-menu-item -->

        </div>
      </div>
    </div>

  <span class="mini-icon help tooltipped downwards" title="Show command bar help">
    <span class="mini-icon mini-icon-help"></span>
  </span>

    <input type="hidden" name="type" value="Code" />

  <input type="hidden" name="ref" value="cmdform">

  <div class="divider-vertical"></div>

</form>
        <ul class="top-nav">
            <li class="explore"><a href="https://github.com/explore">Explore</a></li>
            <li><a href="https://gist.github.com">Gist</a></li>
            <li><a href="/blog">Blog</a></li>
          <li><a href="http://help.github.com">Help</a></li>
        </ul>
      </div>

    

  

    <ul id="user-links">
      <li>
        <a href="https://github.com/matthuxford" class="name">
          <img height="20" src="https://secure.gravatar.com/avatar/159652c8fcc2a050d13498a7c3af0bba?s=140&amp;d=https://a248.e.akamai.net/assets.github.com%2Fimages%2Fgravatars%2Fgravatar-user-420.png" width="20" /> matthuxford
        </a>
      </li>

        <li>
          <a href="/new" id="new_repo" class="tooltipped downwards" title="Create a new repo">
            <span class="mini-icon mini-icon-create"></span>
          </a>
        </li>

        <li>
          <a href="/settings/profile" id="account_settings"
            class="tooltipped downwards"
            title="Account settings ">
            <span class="mini-icon mini-icon-account-settings"></span>
          </a>
        </li>
        <li>
          <a class="tooltipped downwards" href="/logout" data-method="post" id="logout" title="Sign out">
            <span class="mini-icon mini-icon-logout"></span>
          </a>
        </li>

    </ul>


<div class="js-new-dropdown-contents hidden">
  <ul class="dropdown-menu">
    <li>
      <a href="/new"><span class="mini-icon mini-icon-create"></span> New repository</a>
    </li>
    <li>
        <a href="https://github.com/alexsleat/projectChimaera/issues/new"><span class="mini-icon mini-icon-issue-opened"></span> New issue</a>
    </li>
    <li>
    </li>
    <li>
      <a href="/organizations/new"><span class="mini-icon mini-icon-u-list"></span> New organization</a>
    </li>
  </ul>
</div>


    
  </div>
</div>

      

      

      


            <div class="site hfeed" itemscope itemtype="http://schema.org/WebPage">
      <div class="hentry">
        
        <div class="pagehead repohead instapaper_ignore readability-menu ">
          <div class="container">
            <div class="title-actions-bar">
              

<ul class="pagehead-actions">


    <li class="subscription">
      <form accept-charset="UTF-8" action="/notifications/subscribe" data-autosubmit="true" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="authenticity_token" type="hidden" value="E/J5yMbdx1u/0AjbIXscdtgDWlF6wTc5JrXKQJCYF2M=" /></div>  <input id="repository_id" name="repository_id" type="hidden" value="2822251" />

    <div class="select-menu js-menu-container js-select-menu">
      <span class="minibutton select-menu-button js-menu-target">
        <span class="js-select-button">
          <span class="mini-icon mini-icon-watching"></span>
          Watch
        </span>
      </span>

      <div class="select-menu-modal-holder js-menu-content">
        <div class="select-menu-modal">
          <div class="select-menu-header">
            <span class="select-menu-title">Notification status</span>
            <span class="mini-icon mini-icon-remove-close js-menu-close"></span>
          </div> <!-- /.select-menu-header -->

          <div class="select-menu-list js-navigation-container">

            <div class="select-menu-item js-navigation-item selected">
              <span class="select-menu-item-icon mini-icon mini-icon-confirm"></span>
              <div class="select-menu-item-text">
                <input checked="checked" id="do_included" name="do" type="radio" value="included" />
                <h4>Not watching</h4>
                <span class="description">You only receive notifications for discussions in which you participate or are @mentioned.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="mini-icon mini-icon-watching"></span>
                  Watch
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon mini-icon mini-icon-confirm"></span>
              <div class="select-menu-item-text">
                <input id="do_subscribed" name="do" type="radio" value="subscribed" />
                <h4>Watching</h4>
                <span class="description">You receive notifications for all discussions in this repository.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="mini-icon mini-icon-unwatch"></span>
                  Unwatch
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon mini-icon mini-icon-confirm"></span>
              <div class="select-menu-item-text">
                <input id="do_ignore" name="do" type="radio" value="ignore" />
                <h4>Ignoring</h4>
                <span class="description">You do not receive any notifications for discussions in this repository.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="mini-icon mini-icon-mute"></span>
                  Stop ignoring
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

          </div> <!-- /.select-menu-list -->

        </div> <!-- /.select-menu-modal -->
      </div> <!-- /.select-menu-modal-holder -->
    </div> <!-- /.select-menu -->

</form>
    </li>

    <li class="js-toggler-container js-social-container starring-container ">
      <a href="/alexsleat/projectChimaera/unstar" class="minibutton js-toggler-target star-button starred upwards" title="Unstar this repo" data-remote="true" data-method="post" rel="nofollow">
        <span class="mini-icon mini-icon-remove-star"></span>
        <span class="text">Unstar</span>
      </a>
      <a href="/alexsleat/projectChimaera/star" class="minibutton js-toggler-target star-button unstarred upwards" title="Star this repo" data-remote="true" data-method="post" rel="nofollow">
        <span class="mini-icon mini-icon-star"></span>
        <span class="text">Star</span>
      </a>
      <a class="social-count js-social-count" href="/alexsleat/projectChimaera/stargazers">5</a>
    </li>

        <li>
          <a href="/alexsleat/projectChimaera/fork" class="minibutton js-toggler-target fork-button lighter upwards" title="Fork this repo" rel="nofollow" data-method="post">
            <span class="mini-icon mini-icon-branch-create"></span>
            <span class="text">Fork</span>
          </a>
          <a href="/alexsleat/projectChimaera/network" class="social-count">1</a>
        </li>


</ul>

              <h1 itemscope itemtype="http://data-vocabulary.org/Breadcrumb" class="entry-title public">
                <span class="repo-label"><span>public</span></span>
                <span class="mega-icon mega-icon-repo-forked"></span>
                <span class="author vcard">
                  <a href="/alexsleat" class="url fn" itemprop="url" rel="author">
                  <span itemprop="title">alexsleat</span>
                  </a></span> /
                <strong><a href="/alexsleat/projectChimaera" class="js-current-repository">projectChimaera</a></strong>
                  <span class="fork-flag">
                    <span class="text">forked from <a href="/GarethG/ProjectRinzler">GarethG/ProjectRinzler</a></span>
                  </span>
              </h1>
            </div>

            
  <ul class="tabs">
    <li class="pulse-nav"><a href="/alexsleat/projectChimaera/pulse" class="js-selected-navigation-item " data-selected-links="pulse /alexsleat/projectChimaera/pulse" rel="nofollow"><span class="mini-icon mini-icon-pulse"></span></a></li>
    <li><a href="/alexsleat/projectChimaera" class="js-selected-navigation-item selected" data-selected-links="repo_source repo_downloads repo_commits repo_tags repo_branches /alexsleat/projectChimaera">Code</a></li>
    <li><a href="/alexsleat/projectChimaera/network" class="js-selected-navigation-item " data-selected-links="repo_network /alexsleat/projectChimaera/network">Network</a></li>
    <li><a href="/alexsleat/projectChimaera/pulls" class="js-selected-navigation-item " data-selected-links="repo_pulls /alexsleat/projectChimaera/pulls">Pull Requests <span class='counter'>0</span></a></li>

      <li><a href="/alexsleat/projectChimaera/issues" class="js-selected-navigation-item " data-selected-links="repo_issues /alexsleat/projectChimaera/issues">Issues <span class='counter'>10</span></a></li>

      <li><a href="/alexsleat/projectChimaera/wiki" class="js-selected-navigation-item " data-selected-links="repo_wiki /alexsleat/projectChimaera/wiki">Wiki</a></li>


    <li><a href="/alexsleat/projectChimaera/graphs" class="js-selected-navigation-item " data-selected-links="repo_graphs repo_contributors /alexsleat/projectChimaera/graphs">Graphs</a></li>


  </ul>
  
<div class="tabnav">

  <span class="tabnav-right">
    <ul class="tabnav-tabs">
          <li><a href="/alexsleat/projectChimaera/tags" class="js-selected-navigation-item tabnav-tab" data-selected-links="repo_tags /alexsleat/projectChimaera/tags">Tags <span class="counter blank">0</span></a></li>
    </ul>
  </span>

  <div class="tabnav-widget scope">


    <div class="select-menu js-menu-container js-select-menu js-branch-menu">
      <a class="minibutton select-menu-button js-menu-target" data-hotkey="w" data-ref="master">
        <span class="mini-icon mini-icon-branch"></span>
        <i>branch:</i>
        <span class="js-select-button">master</span>
      </a>

      <div class="select-menu-modal-holder js-menu-content js-navigation-container">

        <div class="select-menu-modal">
          <div class="select-menu-header">
            <span class="select-menu-title">Switch branches/tags</span>
            <span class="mini-icon mini-icon-remove-close js-menu-close"></span>
          </div> <!-- /.select-menu-header -->

          <div class="select-menu-filters">
            <div class="select-menu-text-filter">
              <input type="text" id="commitish-filter-field" class="js-filterable-field js-navigation-enable" placeholder="Filter branches/tags">
            </div>
            <div class="select-menu-tabs">
              <ul>
                <li class="select-menu-tab">
                  <a href="#" data-tab-filter="branches" class="js-select-menu-tab">Branches</a>
                </li>
                <li class="select-menu-tab">
                  <a href="#" data-tab-filter="tags" class="js-select-menu-tab">Tags</a>
                </li>
              </ul>
            </div><!-- /.select-menu-tabs -->
          </div><!-- /.select-menu-filters -->

          <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket css-truncate" data-tab-filter="branches">

            <div data-filterable-for="commitish-filter-field" data-filterable-type="substring">

                <div class="select-menu-item js-navigation-item selected">
                  <span class="select-menu-item-icon mini-icon mini-icon-confirm"></span>
                  <a href="/alexsleat/projectChimaera/blob/master/Drivers/vNavIMU/src/vncp_services.c" class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target" data-name="master" rel="nofollow" title="master">master</a>
                </div> <!-- /.select-menu-item -->
            </div>

              <div class="select-menu-no-results">Nothing to show</div>
          </div> <!-- /.select-menu-list -->


          <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket css-truncate" data-tab-filter="tags">
            <div data-filterable-for="commitish-filter-field" data-filterable-type="substring">

            </div>

            <div class="select-menu-no-results">Nothing to show</div>

          </div> <!-- /.select-menu-list -->

        </div> <!-- /.select-menu-modal -->
      </div> <!-- /.select-menu-modal-holder -->
    </div> <!-- /.select-menu -->

  </div> <!-- /.scope -->

  <ul class="tabnav-tabs">
    <li><a href="/alexsleat/projectChimaera" class="selected js-selected-navigation-item tabnav-tab" data-selected-links="repo_source /alexsleat/projectChimaera">Files</a></li>
    <li><a href="/alexsleat/projectChimaera/commits/master" class="js-selected-navigation-item tabnav-tab" data-selected-links="repo_commits /alexsleat/projectChimaera/commits/master">Commits</a></li>
    <li><a href="/alexsleat/projectChimaera/branches" class="js-selected-navigation-item tabnav-tab" data-selected-links="repo_branches /alexsleat/projectChimaera/branches" rel="nofollow">Branches <span class="counter ">1</span></a></li>
  </ul>

</div>

  
  
  


            
          </div>
        </div><!-- /.repohead -->

        <div id="js-repo-pjax-container" class="container context-loader-container" data-pjax-container>
          


<!-- blob contrib key: blob_contributors:v21:bfd65cab05a6db07496f911d2d4ce254 -->
<!-- blob contrib frag key: views10/v8/blob_contributors:v21:bfd65cab05a6db07496f911d2d4ce254 -->


<div id="slider">
    <div class="frame-meta">

      <p title="This is a placeholder element" class="js-history-link-replace hidden"></p>

        <div class="breadcrumb">
          <span class='bold'><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/alexsleat/projectChimaera" class="js-slide-to" data-branch="master" data-direction="back" itemscope="url"><span itemprop="title">projectChimaera</span></a></span></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/alexsleat/projectChimaera/tree/master/Drivers" class="js-slide-to" data-branch="master" data-direction="back" itemscope="url"><span itemprop="title">Drivers</span></a></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/alexsleat/projectChimaera/tree/master/Drivers/vNavIMU" class="js-slide-to" data-branch="master" data-direction="back" itemscope="url"><span itemprop="title">vNavIMU</span></a></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/alexsleat/projectChimaera/tree/master/Drivers/vNavIMU/src" class="js-slide-to" data-branch="master" data-direction="back" itemscope="url"><span itemprop="title">src</span></a></span><span class="separator"> / </span><strong class="final-path">vncp_services.c</strong> <span class="js-zeroclipboard zeroclipboard-button" data-clipboard-text="Drivers/vNavIMU/src/vncp_services.c" data-copied-hint="copied!" title="copy to clipboard"><span class="mini-icon mini-icon-clipboard"></span></span>
        </div>

      <a href="/alexsleat/projectChimaera/find/master" class="js-slide-to" data-hotkey="t" style="display:none">Show File Finder</a>


        <div class="commit commit-loader file-history-tease js-deferred-content" data-url="/alexsleat/projectChimaera/contributors/master/Drivers/vNavIMU/src/vncp_services.c">
          Fetching contributors…

          <div class="participation">
            <p class="loader-loading"><img alt="Octocat-spinner-32-eaf2f5" height="16" src="https://a248.e.akamai.net/assets.github.com/images/spinners/octocat-spinner-32-EAF2F5.gif?1340659561" width="16" /></p>
            <p class="loader-error">Cannot retrieve contributors at this time</p>
          </div>
        </div>

    </div><!-- ./.frame-meta -->

    <div class="frames">
      <div class="frame" data-permalink-url="/alexsleat/projectChimaera/blob/636edcda74a3a158bf88efae8b7814645184a1b3/Drivers/vNavIMU/src/vncp_services.c" data-title="projectChimaera/Drivers/vNavIMU/src/vncp_services.c at master · alexsleat/projectChimaera · GitHub" data-type="blob">

        <div id="files" class="bubble">
          <div class="file">
            <div class="meta">
              <div class="info">
                <span class="icon"><b class="mini-icon mini-icon-text-file"></b></span>
                <span class="mode" title="File Mode">file</span>
                  <span>358 lines (261 sloc)</span>
                <span>9.82 kb</span>
              </div>
              <div class="actions">
                <div class="button-group">
                        <a class="minibutton tooltipped leftwards"
                           title="Clicking this button will automatically fork this project so you can edit the file"
                           href="/alexsleat/projectChimaera/edit/master/Drivers/vNavIMU/src/vncp_services.c"
                           data-method="post" rel="nofollow">Edit</a>
                  <a href="/alexsleat/projectChimaera/raw/master/Drivers/vNavIMU/src/vncp_services.c" class="button minibutton " id="raw-url">Raw</a>
                    <a href="/alexsleat/projectChimaera/blame/master/Drivers/vNavIMU/src/vncp_services.c" class="button minibutton ">Blame</a>
                  <a href="/alexsleat/projectChimaera/commits/master/Drivers/vNavIMU/src/vncp_services.c" class="button minibutton " rel="nofollow">History</a>
                </div><!-- /.button-group -->
              </div><!-- /.actions -->

            </div>
                <div class="blob-wrapper data type-c js-blob-data">
      <table class="file-code file-diff">
        <tr class="file-code-line">
          <td class="blob-line-nums">
            <span id="L1" rel="#L1">1</span>
<span id="L2" rel="#L2">2</span>
<span id="L3" rel="#L3">3</span>
<span id="L4" rel="#L4">4</span>
<span id="L5" rel="#L5">5</span>
<span id="L6" rel="#L6">6</span>
<span id="L7" rel="#L7">7</span>
<span id="L8" rel="#L8">8</span>
<span id="L9" rel="#L9">9</span>
<span id="L10" rel="#L10">10</span>
<span id="L11" rel="#L11">11</span>
<span id="L12" rel="#L12">12</span>
<span id="L13" rel="#L13">13</span>
<span id="L14" rel="#L14">14</span>
<span id="L15" rel="#L15">15</span>
<span id="L16" rel="#L16">16</span>
<span id="L17" rel="#L17">17</span>
<span id="L18" rel="#L18">18</span>
<span id="L19" rel="#L19">19</span>
<span id="L20" rel="#L20">20</span>
<span id="L21" rel="#L21">21</span>
<span id="L22" rel="#L22">22</span>
<span id="L23" rel="#L23">23</span>
<span id="L24" rel="#L24">24</span>
<span id="L25" rel="#L25">25</span>
<span id="L26" rel="#L26">26</span>
<span id="L27" rel="#L27">27</span>
<span id="L28" rel="#L28">28</span>
<span id="L29" rel="#L29">29</span>
<span id="L30" rel="#L30">30</span>
<span id="L31" rel="#L31">31</span>
<span id="L32" rel="#L32">32</span>
<span id="L33" rel="#L33">33</span>
<span id="L34" rel="#L34">34</span>
<span id="L35" rel="#L35">35</span>
<span id="L36" rel="#L36">36</span>
<span id="L37" rel="#L37">37</span>
<span id="L38" rel="#L38">38</span>
<span id="L39" rel="#L39">39</span>
<span id="L40" rel="#L40">40</span>
<span id="L41" rel="#L41">41</span>
<span id="L42" rel="#L42">42</span>
<span id="L43" rel="#L43">43</span>
<span id="L44" rel="#L44">44</span>
<span id="L45" rel="#L45">45</span>
<span id="L46" rel="#L46">46</span>
<span id="L47" rel="#L47">47</span>
<span id="L48" rel="#L48">48</span>
<span id="L49" rel="#L49">49</span>
<span id="L50" rel="#L50">50</span>
<span id="L51" rel="#L51">51</span>
<span id="L52" rel="#L52">52</span>
<span id="L53" rel="#L53">53</span>
<span id="L54" rel="#L54">54</span>
<span id="L55" rel="#L55">55</span>
<span id="L56" rel="#L56">56</span>
<span id="L57" rel="#L57">57</span>
<span id="L58" rel="#L58">58</span>
<span id="L59" rel="#L59">59</span>
<span id="L60" rel="#L60">60</span>
<span id="L61" rel="#L61">61</span>
<span id="L62" rel="#L62">62</span>
<span id="L63" rel="#L63">63</span>
<span id="L64" rel="#L64">64</span>
<span id="L65" rel="#L65">65</span>
<span id="L66" rel="#L66">66</span>
<span id="L67" rel="#L67">67</span>
<span id="L68" rel="#L68">68</span>
<span id="L69" rel="#L69">69</span>
<span id="L70" rel="#L70">70</span>
<span id="L71" rel="#L71">71</span>
<span id="L72" rel="#L72">72</span>
<span id="L73" rel="#L73">73</span>
<span id="L74" rel="#L74">74</span>
<span id="L75" rel="#L75">75</span>
<span id="L76" rel="#L76">76</span>
<span id="L77" rel="#L77">77</span>
<span id="L78" rel="#L78">78</span>
<span id="L79" rel="#L79">79</span>
<span id="L80" rel="#L80">80</span>
<span id="L81" rel="#L81">81</span>
<span id="L82" rel="#L82">82</span>
<span id="L83" rel="#L83">83</span>
<span id="L84" rel="#L84">84</span>
<span id="L85" rel="#L85">85</span>
<span id="L86" rel="#L86">86</span>
<span id="L87" rel="#L87">87</span>
<span id="L88" rel="#L88">88</span>
<span id="L89" rel="#L89">89</span>
<span id="L90" rel="#L90">90</span>
<span id="L91" rel="#L91">91</span>
<span id="L92" rel="#L92">92</span>
<span id="L93" rel="#L93">93</span>
<span id="L94" rel="#L94">94</span>
<span id="L95" rel="#L95">95</span>
<span id="L96" rel="#L96">96</span>
<span id="L97" rel="#L97">97</span>
<span id="L98" rel="#L98">98</span>
<span id="L99" rel="#L99">99</span>
<span id="L100" rel="#L100">100</span>
<span id="L101" rel="#L101">101</span>
<span id="L102" rel="#L102">102</span>
<span id="L103" rel="#L103">103</span>
<span id="L104" rel="#L104">104</span>
<span id="L105" rel="#L105">105</span>
<span id="L106" rel="#L106">106</span>
<span id="L107" rel="#L107">107</span>
<span id="L108" rel="#L108">108</span>
<span id="L109" rel="#L109">109</span>
<span id="L110" rel="#L110">110</span>
<span id="L111" rel="#L111">111</span>
<span id="L112" rel="#L112">112</span>
<span id="L113" rel="#L113">113</span>
<span id="L114" rel="#L114">114</span>
<span id="L115" rel="#L115">115</span>
<span id="L116" rel="#L116">116</span>
<span id="L117" rel="#L117">117</span>
<span id="L118" rel="#L118">118</span>
<span id="L119" rel="#L119">119</span>
<span id="L120" rel="#L120">120</span>
<span id="L121" rel="#L121">121</span>
<span id="L122" rel="#L122">122</span>
<span id="L123" rel="#L123">123</span>
<span id="L124" rel="#L124">124</span>
<span id="L125" rel="#L125">125</span>
<span id="L126" rel="#L126">126</span>
<span id="L127" rel="#L127">127</span>
<span id="L128" rel="#L128">128</span>
<span id="L129" rel="#L129">129</span>
<span id="L130" rel="#L130">130</span>
<span id="L131" rel="#L131">131</span>
<span id="L132" rel="#L132">132</span>
<span id="L133" rel="#L133">133</span>
<span id="L134" rel="#L134">134</span>
<span id="L135" rel="#L135">135</span>
<span id="L136" rel="#L136">136</span>
<span id="L137" rel="#L137">137</span>
<span id="L138" rel="#L138">138</span>
<span id="L139" rel="#L139">139</span>
<span id="L140" rel="#L140">140</span>
<span id="L141" rel="#L141">141</span>
<span id="L142" rel="#L142">142</span>
<span id="L143" rel="#L143">143</span>
<span id="L144" rel="#L144">144</span>
<span id="L145" rel="#L145">145</span>
<span id="L146" rel="#L146">146</span>
<span id="L147" rel="#L147">147</span>
<span id="L148" rel="#L148">148</span>
<span id="L149" rel="#L149">149</span>
<span id="L150" rel="#L150">150</span>
<span id="L151" rel="#L151">151</span>
<span id="L152" rel="#L152">152</span>
<span id="L153" rel="#L153">153</span>
<span id="L154" rel="#L154">154</span>
<span id="L155" rel="#L155">155</span>
<span id="L156" rel="#L156">156</span>
<span id="L157" rel="#L157">157</span>
<span id="L158" rel="#L158">158</span>
<span id="L159" rel="#L159">159</span>
<span id="L160" rel="#L160">160</span>
<span id="L161" rel="#L161">161</span>
<span id="L162" rel="#L162">162</span>
<span id="L163" rel="#L163">163</span>
<span id="L164" rel="#L164">164</span>
<span id="L165" rel="#L165">165</span>
<span id="L166" rel="#L166">166</span>
<span id="L167" rel="#L167">167</span>
<span id="L168" rel="#L168">168</span>
<span id="L169" rel="#L169">169</span>
<span id="L170" rel="#L170">170</span>
<span id="L171" rel="#L171">171</span>
<span id="L172" rel="#L172">172</span>
<span id="L173" rel="#L173">173</span>
<span id="L174" rel="#L174">174</span>
<span id="L175" rel="#L175">175</span>
<span id="L176" rel="#L176">176</span>
<span id="L177" rel="#L177">177</span>
<span id="L178" rel="#L178">178</span>
<span id="L179" rel="#L179">179</span>
<span id="L180" rel="#L180">180</span>
<span id="L181" rel="#L181">181</span>
<span id="L182" rel="#L182">182</span>
<span id="L183" rel="#L183">183</span>
<span id="L184" rel="#L184">184</span>
<span id="L185" rel="#L185">185</span>
<span id="L186" rel="#L186">186</span>
<span id="L187" rel="#L187">187</span>
<span id="L188" rel="#L188">188</span>
<span id="L189" rel="#L189">189</span>
<span id="L190" rel="#L190">190</span>
<span id="L191" rel="#L191">191</span>
<span id="L192" rel="#L192">192</span>
<span id="L193" rel="#L193">193</span>
<span id="L194" rel="#L194">194</span>
<span id="L195" rel="#L195">195</span>
<span id="L196" rel="#L196">196</span>
<span id="L197" rel="#L197">197</span>
<span id="L198" rel="#L198">198</span>
<span id="L199" rel="#L199">199</span>
<span id="L200" rel="#L200">200</span>
<span id="L201" rel="#L201">201</span>
<span id="L202" rel="#L202">202</span>
<span id="L203" rel="#L203">203</span>
<span id="L204" rel="#L204">204</span>
<span id="L205" rel="#L205">205</span>
<span id="L206" rel="#L206">206</span>
<span id="L207" rel="#L207">207</span>
<span id="L208" rel="#L208">208</span>
<span id="L209" rel="#L209">209</span>
<span id="L210" rel="#L210">210</span>
<span id="L211" rel="#L211">211</span>
<span id="L212" rel="#L212">212</span>
<span id="L213" rel="#L213">213</span>
<span id="L214" rel="#L214">214</span>
<span id="L215" rel="#L215">215</span>
<span id="L216" rel="#L216">216</span>
<span id="L217" rel="#L217">217</span>
<span id="L218" rel="#L218">218</span>
<span id="L219" rel="#L219">219</span>
<span id="L220" rel="#L220">220</span>
<span id="L221" rel="#L221">221</span>
<span id="L222" rel="#L222">222</span>
<span id="L223" rel="#L223">223</span>
<span id="L224" rel="#L224">224</span>
<span id="L225" rel="#L225">225</span>
<span id="L226" rel="#L226">226</span>
<span id="L227" rel="#L227">227</span>
<span id="L228" rel="#L228">228</span>
<span id="L229" rel="#L229">229</span>
<span id="L230" rel="#L230">230</span>
<span id="L231" rel="#L231">231</span>
<span id="L232" rel="#L232">232</span>
<span id="L233" rel="#L233">233</span>
<span id="L234" rel="#L234">234</span>
<span id="L235" rel="#L235">235</span>
<span id="L236" rel="#L236">236</span>
<span id="L237" rel="#L237">237</span>
<span id="L238" rel="#L238">238</span>
<span id="L239" rel="#L239">239</span>
<span id="L240" rel="#L240">240</span>
<span id="L241" rel="#L241">241</span>
<span id="L242" rel="#L242">242</span>
<span id="L243" rel="#L243">243</span>
<span id="L244" rel="#L244">244</span>
<span id="L245" rel="#L245">245</span>
<span id="L246" rel="#L246">246</span>
<span id="L247" rel="#L247">247</span>
<span id="L248" rel="#L248">248</span>
<span id="L249" rel="#L249">249</span>
<span id="L250" rel="#L250">250</span>
<span id="L251" rel="#L251">251</span>
<span id="L252" rel="#L252">252</span>
<span id="L253" rel="#L253">253</span>
<span id="L254" rel="#L254">254</span>
<span id="L255" rel="#L255">255</span>
<span id="L256" rel="#L256">256</span>
<span id="L257" rel="#L257">257</span>
<span id="L258" rel="#L258">258</span>
<span id="L259" rel="#L259">259</span>
<span id="L260" rel="#L260">260</span>
<span id="L261" rel="#L261">261</span>
<span id="L262" rel="#L262">262</span>
<span id="L263" rel="#L263">263</span>
<span id="L264" rel="#L264">264</span>
<span id="L265" rel="#L265">265</span>
<span id="L266" rel="#L266">266</span>
<span id="L267" rel="#L267">267</span>
<span id="L268" rel="#L268">268</span>
<span id="L269" rel="#L269">269</span>
<span id="L270" rel="#L270">270</span>
<span id="L271" rel="#L271">271</span>
<span id="L272" rel="#L272">272</span>
<span id="L273" rel="#L273">273</span>
<span id="L274" rel="#L274">274</span>
<span id="L275" rel="#L275">275</span>
<span id="L276" rel="#L276">276</span>
<span id="L277" rel="#L277">277</span>
<span id="L278" rel="#L278">278</span>
<span id="L279" rel="#L279">279</span>
<span id="L280" rel="#L280">280</span>
<span id="L281" rel="#L281">281</span>
<span id="L282" rel="#L282">282</span>
<span id="L283" rel="#L283">283</span>
<span id="L284" rel="#L284">284</span>
<span id="L285" rel="#L285">285</span>
<span id="L286" rel="#L286">286</span>
<span id="L287" rel="#L287">287</span>
<span id="L288" rel="#L288">288</span>
<span id="L289" rel="#L289">289</span>
<span id="L290" rel="#L290">290</span>
<span id="L291" rel="#L291">291</span>
<span id="L292" rel="#L292">292</span>
<span id="L293" rel="#L293">293</span>
<span id="L294" rel="#L294">294</span>
<span id="L295" rel="#L295">295</span>
<span id="L296" rel="#L296">296</span>
<span id="L297" rel="#L297">297</span>
<span id="L298" rel="#L298">298</span>
<span id="L299" rel="#L299">299</span>
<span id="L300" rel="#L300">300</span>
<span id="L301" rel="#L301">301</span>
<span id="L302" rel="#L302">302</span>
<span id="L303" rel="#L303">303</span>
<span id="L304" rel="#L304">304</span>
<span id="L305" rel="#L305">305</span>
<span id="L306" rel="#L306">306</span>
<span id="L307" rel="#L307">307</span>
<span id="L308" rel="#L308">308</span>
<span id="L309" rel="#L309">309</span>
<span id="L310" rel="#L310">310</span>
<span id="L311" rel="#L311">311</span>
<span id="L312" rel="#L312">312</span>
<span id="L313" rel="#L313">313</span>
<span id="L314" rel="#L314">314</span>
<span id="L315" rel="#L315">315</span>
<span id="L316" rel="#L316">316</span>
<span id="L317" rel="#L317">317</span>
<span id="L318" rel="#L318">318</span>
<span id="L319" rel="#L319">319</span>
<span id="L320" rel="#L320">320</span>
<span id="L321" rel="#L321">321</span>
<span id="L322" rel="#L322">322</span>
<span id="L323" rel="#L323">323</span>
<span id="L324" rel="#L324">324</span>
<span id="L325" rel="#L325">325</span>
<span id="L326" rel="#L326">326</span>
<span id="L327" rel="#L327">327</span>
<span id="L328" rel="#L328">328</span>
<span id="L329" rel="#L329">329</span>
<span id="L330" rel="#L330">330</span>
<span id="L331" rel="#L331">331</span>
<span id="L332" rel="#L332">332</span>
<span id="L333" rel="#L333">333</span>
<span id="L334" rel="#L334">334</span>
<span id="L335" rel="#L335">335</span>
<span id="L336" rel="#L336">336</span>
<span id="L337" rel="#L337">337</span>
<span id="L338" rel="#L338">338</span>
<span id="L339" rel="#L339">339</span>
<span id="L340" rel="#L340">340</span>
<span id="L341" rel="#L341">341</span>
<span id="L342" rel="#L342">342</span>
<span id="L343" rel="#L343">343</span>
<span id="L344" rel="#L344">344</span>
<span id="L345" rel="#L345">345</span>
<span id="L346" rel="#L346">346</span>
<span id="L347" rel="#L347">347</span>
<span id="L348" rel="#L348">348</span>
<span id="L349" rel="#L349">349</span>
<span id="L350" rel="#L350">350</span>
<span id="L351" rel="#L351">351</span>
<span id="L352" rel="#L352">352</span>
<span id="L353" rel="#L353">353</span>
<span id="L354" rel="#L354">354</span>
<span id="L355" rel="#L355">355</span>
<span id="L356" rel="#L356">356</span>
<span id="L357" rel="#L357">357</span>

          </td>
          <td class="blob-line-code">
                  <div class="highlight"><pre><div class='line' id='LC1'><span class="cm">/**</span></div><div class='line' id='LC2'><span class="cm"> * \cond INCLUDE_PRIVATE</span></div><div class='line' id='LC3'><span class="cm"> * \file</span></div><div class='line' id='LC4'><span class="cm"> *</span></div><div class='line' id='LC5'><span class="cm"> * \section LICENSE</span></div><div class='line' id='LC6'><span class="cm"> * MIT License (MIT)</span></div><div class='line' id='LC7'><span class="cm"> *</span></div><div class='line' id='LC8'><span class="cm"> * Copyright (c) 2011 VectorNav Technologies, LLC</span></div><div class='line' id='LC9'><span class="cm"> *</span></div><div class='line' id='LC10'><span class="cm"> * Permission is hereby granted, free of charge, to any person obtaining a copy</span></div><div class='line' id='LC11'><span class="cm"> * of this software and associated documentation files (the &quot;Software&quot;), to</span></div><div class='line' id='LC12'><span class="cm"> * deal in the Software without restriction, including without limitation the</span></div><div class='line' id='LC13'><span class="cm"> * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or</span></div><div class='line' id='LC14'><span class="cm"> * sell copies of the Software, and to permit persons to whom the Software is</span></div><div class='line' id='LC15'><span class="cm"> * furnished to do so, subject to the following conditions:</span></div><div class='line' id='LC16'><span class="cm"> *</span></div><div class='line' id='LC17'><span class="cm"> * The above copyright notice and this permission notice shall be included in</span></div><div class='line' id='LC18'><span class="cm"> * all copies or substantial portions of the Software.</span></div><div class='line' id='LC19'><span class="cm"> *</span></div><div class='line' id='LC20'><span class="cm"> * THE SOFTWARE IS PROVIDED &quot;AS IS&quot;, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR</span></div><div class='line' id='LC21'><span class="cm"> * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,</span></div><div class='line' id='LC22'><span class="cm"> * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE</span></div><div class='line' id='LC23'><span class="cm"> * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER</span></div><div class='line' id='LC24'><span class="cm"> * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING</span></div><div class='line' id='LC25'><span class="cm"> * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS</span></div><div class='line' id='LC26'><span class="cm"> * IN THE SOFTWARE.</span></div><div class='line' id='LC27'><span class="cm"> *</span></div><div class='line' id='LC28'><span class="cm"> * \section DESCRIPTION</span></div><div class='line' id='LC29'><span class="cm"> * This file supplies the cross-platform services when on a Linux machine.</span></div><div class='line' id='LC30'><span class="cm"> */</span></div><div class='line' id='LC31'><span class="cp">#include &lt;stdlib.h&gt;</span></div><div class='line' id='LC32'><span class="cp">#include &lt;unistd.h&gt;</span></div><div class='line' id='LC33'><span class="cp">#include &lt;fcntl.h&gt;</span></div><div class='line' id='LC34'><span class="cp">#include &lt;termios.h&gt;</span></div><div class='line' id='LC35'><span class="cp">#include &lt;errno.h&gt;</span></div><div class='line' id='LC36'><span class="cp">#include &lt;string.h&gt;</span></div><div class='line' id='LC37'><span class="cp">#include &quot;../include/vNavIMU/vncp_services.h&quot;</span></div><div class='line' id='LC38'><span class="cp">#include &quot;../include/vNavIMU/vn_errorCodes.h&quot;</span></div><div class='line' id='LC39'><br/></div><div class='line' id='LC40'><span class="cm">/* Private type declarations. ************************************************/</span></div><div class='line' id='LC41'><span class="k">typedef</span> <span class="k">struct</span> <span class="p">{</span></div><div class='line' id='LC42'>	<span class="n">VN_THREAD_START_ROUTINE</span>	<span class="n">startRoutine</span><span class="p">;</span></div><div class='line' id='LC43'>	<span class="kt">void</span><span class="o">*</span>					<span class="n">routineData</span><span class="p">;</span></div><div class='line' id='LC44'><span class="p">}</span> <span class="n">VncpThreadStartData</span><span class="p">;</span></div><div class='line' id='LC45'><br/></div><div class='line' id='LC46'><span class="k">typedef</span> <span class="k">struct</span> <span class="p">{</span></div><div class='line' id='LC47'>	<span class="kt">pthread_mutex_t</span>		<span class="n">mutex</span><span class="p">;</span></div><div class='line' id='LC48'>	<span class="kt">pthread_cond_t</span>		<span class="n">condition</span><span class="p">;</span></div><div class='line' id='LC49'>	<span class="n">VN_BOOL</span>				<span class="n">isTriggered</span><span class="p">;</span></div><div class='line' id='LC50'><span class="p">}</span> <span class="n">VncpConditionAndMutex</span><span class="p">;</span></div><div class='line' id='LC51'><br/></div><div class='line' id='LC52'><span class="cm">/* Private function declarations. ********************************************/</span></div><div class='line' id='LC53'><span class="kt">void</span><span class="o">*</span> <span class="nf">vncp_thread_startRoutine</span><span class="p">(</span><span class="kt">void</span><span class="o">*</span> <span class="n">threadStartData</span><span class="p">);</span></div><div class='line' id='LC54'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_convertNativeToVnErrorCode</span><span class="p">(</span><span class="kt">int</span> <span class="n">nativeErrorCode</span><span class="p">);</span></div><div class='line' id='LC55'><br/></div><div class='line' id='LC56'><span class="cm">/**</span></div><div class='line' id='LC57'><span class="cm"> * \brief Determines what the baudrate flag should be for the provide baudrate.</span></div><div class='line' id='LC58'><span class="cm"> *</span></div><div class='line' id='LC59'><span class="cm"> * \param[in]	baudrate	Desired baudrate.</span></div><div class='line' id='LC60'><span class="cm"> * \return The appropriate baudrate flag to set in the termios.c_cflag field to</span></div><div class='line' id='LC61'><span class="cm"> * get the desired baudrate. If the provided baudrate is invalid, the value B0</span></div><div class='line' id='LC62'><span class="cm"> * will be returned.</span></div><div class='line' id='LC63'><span class="cm"> */</span></div><div class='line' id='LC64'><span class="kt">tcflag_t</span> <span class="nf">vncp_determineBaudrateFlag</span><span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">baudrate</span><span class="p">);</span></div><div class='line' id='LC65'><br/></div><div class='line' id='LC66'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_thread_startNew</span><span class="p">(</span><span class="n">VN_HANDLE</span><span class="o">*</span> <span class="n">newThreadHandle</span><span class="p">,</span> <span class="n">VN_THREAD_START_ROUTINE</span> <span class="n">startRoutine</span><span class="p">,</span> <span class="kt">void</span><span class="o">*</span> <span class="n">routineData</span><span class="p">)</span></div><div class='line' id='LC67'><span class="p">{</span></div><div class='line' id='LC68'>	<span class="kt">int</span> <span class="n">errorCode</span><span class="p">;</span></div><div class='line' id='LC69'><br/></div><div class='line' id='LC70'>	<span class="n">VncpThreadStartData</span><span class="o">*</span> <span class="n">data</span> <span class="o">=</span> <span class="p">(</span><span class="n">VncpThreadStartData</span><span class="o">*</span><span class="p">)</span> <span class="n">malloc</span><span class="p">(</span><span class="k">sizeof</span><span class="p">(</span><span class="n">VncpThreadStartData</span><span class="p">));</span></div><div class='line' id='LC71'><br/></div><div class='line' id='LC72'>	<span class="n">data</span><span class="o">-&gt;</span><span class="n">startRoutine</span> <span class="o">=</span> <span class="n">startRoutine</span><span class="p">;</span></div><div class='line' id='LC73'>	<span class="n">data</span><span class="o">-&gt;</span><span class="n">routineData</span> <span class="o">=</span> <span class="n">routineData</span><span class="p">;</span></div><div class='line' id='LC74'><br/></div><div class='line' id='LC75'>	<span class="n">errorCode</span> <span class="o">=</span> <span class="n">pthread_create</span><span class="p">(</span><span class="o">&amp;</span><span class="n">newThreadHandle</span><span class="o">-&gt;</span><span class="n">pThreadHandle</span><span class="p">,</span> <span class="nb">NULL</span><span class="p">,</span> <span class="n">vncp_thread_startRoutine</span><span class="p">,</span> <span class="n">data</span><span class="p">);</span></div><div class='line' id='LC76'><br/></div><div class='line' id='LC77'>	<span class="k">if</span> <span class="p">(</span><span class="n">errorCode</span> <span class="o">!=</span> <span class="mi">0</span><span class="p">)</span></div><div class='line' id='LC78'>		<span class="k">return</span> <span class="n">vncp_convertNativeToVnErrorCode</span><span class="p">(</span><span class="n">errorCode</span><span class="p">);</span></div><div class='line' id='LC79'><br/></div><div class='line' id='LC80'>	<span class="k">return</span> <span class="n">VNERR_NO_ERROR</span><span class="p">;</span></div><div class='line' id='LC81'><span class="p">}</span></div><div class='line' id='LC82'><br/></div><div class='line' id='LC83'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_comPort_open</span><span class="p">(</span><span class="n">VN_HANDLE</span><span class="o">*</span> <span class="n">newComPortHandle</span><span class="p">,</span> <span class="kt">char</span> <span class="k">const</span><span class="o">*</span> <span class="n">portName</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">baudrate</span><span class="p">)</span></div><div class='line' id='LC84'><span class="p">{</span></div><div class='line' id='LC85'>	<span class="k">struct</span> <span class="n">termios</span> <span class="n">portSettings</span><span class="p">;</span></div><div class='line' id='LC86'>	<span class="kt">int</span> <span class="n">portFd</span> <span class="o">=</span> <span class="o">-</span><span class="mi">1</span><span class="p">;</span></div><div class='line' id='LC87'>	<span class="kt">tcflag_t</span> <span class="n">baudrateFlag</span><span class="p">;</span></div><div class='line' id='LC88'><br/></div><div class='line' id='LC89'>	<span class="n">portFd</span> <span class="o">=</span> <span class="n">open</span><span class="p">(</span><span class="n">portName</span><span class="p">,</span> <span class="n">O_RDWR</span> <span class="o">|</span> <span class="n">O_NOCTTY</span><span class="p">);</span></div><div class='line' id='LC90'>	<span class="k">if</span> <span class="p">(</span><span class="n">portFd</span> <span class="o">==</span> <span class="o">-</span><span class="mi">1</span><span class="p">)</span></div><div class='line' id='LC91'>		<span class="k">return</span> <span class="n">vncp_convertNativeToVnErrorCode</span><span class="p">(</span><span class="n">errno</span><span class="p">);</span></div><div class='line' id='LC92'><br/></div><div class='line' id='LC93'>	<span class="cm">/* clear struct for new port settings */</span></div><div class='line' id='LC94'>	<span class="n">memset</span><span class="p">(</span><span class="o">&amp;</span><span class="n">portSettings</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="k">sizeof</span><span class="p">(</span><span class="n">portSettings</span><span class="p">));</span></div><div class='line' id='LC95'><br/></div><div class='line' id='LC96'>	<span class="n">baudrateFlag</span> <span class="o">=</span> <span class="n">vncp_determineBaudrateFlag</span><span class="p">(</span><span class="n">baudrate</span><span class="p">);</span></div><div class='line' id='LC97'>	<span class="k">if</span> <span class="p">(</span><span class="n">baudrateFlag</span> <span class="o">==</span> <span class="n">B0</span><span class="p">)</span></div><div class='line' id='LC98'>		<span class="k">return</span> <span class="n">VNERR_UNKNOWN_ERROR</span><span class="p">;</span></div><div class='line' id='LC99'><br/></div><div class='line' id='LC100'>	<span class="cm">/* Set baudrate, 8n1, no modem control, enable receiving characters. */</span></div><div class='line' id='LC101'>	<span class="n">portSettings</span><span class="p">.</span><span class="n">c_cflag</span> <span class="o">=</span> <span class="n">baudrateFlag</span> <span class="o">|</span> <span class="n">CS8</span> <span class="o">|</span> <span class="n">CLOCAL</span> <span class="o">|</span> <span class="n">CREAD</span><span class="p">;</span></div><div class='line' id='LC102'><br/></div><div class='line' id='LC103'>	<span class="n">portSettings</span><span class="p">.</span><span class="n">c_iflag</span> <span class="o">=</span> <span class="n">IGNPAR</span><span class="p">;</span>		<span class="cm">/* Ignore bytes with parity errors. */</span></div><div class='line' id='LC104'>	<span class="n">portSettings</span><span class="p">.</span><span class="n">c_oflag</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span>			<span class="cm">/* Enable raw data output. */</span></div><div class='line' id='LC105'><br/></div><div class='line' id='LC106'>	<span class="n">portSettings</span><span class="p">.</span><span class="n">c_cc</span><span class="p">[</span><span class="n">VTIME</span><span class="p">]</span>    <span class="o">=</span> <span class="mi">0</span><span class="p">;</span>	<span class="cm">/* Do not use inter-character timer. */</span></div><div class='line' id='LC107'>	<span class="n">portSettings</span><span class="p">.</span><span class="n">c_cc</span><span class="p">[</span><span class="n">VMIN</span><span class="p">]</span>     <span class="o">=</span> <span class="mi">0</span><span class="p">;</span>	<span class="cm">/* Block on reads until 0 character is received. */</span></div><div class='line' id='LC108'><br/></div><div class='line' id='LC109'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="cm">/* Clear the COM port buffers. */</span></div><div class='line' id='LC110'>	<span class="k">if</span> <span class="p">(</span><span class="n">tcflush</span><span class="p">(</span><span class="n">portFd</span><span class="p">,</span> <span class="n">TCIFLUSH</span><span class="p">)</span> <span class="o">!=</span> <span class="mi">0</span><span class="p">)</span></div><div class='line' id='LC111'>		<span class="k">return</span> <span class="n">vncp_convertNativeToVnErrorCode</span><span class="p">(</span><span class="n">errno</span><span class="p">);</span></div><div class='line' id='LC112'><br/></div><div class='line' id='LC113'>	<span class="k">if</span> <span class="p">(</span><span class="n">tcsetattr</span><span class="p">(</span><span class="n">portFd</span><span class="p">,</span> <span class="n">TCSANOW</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">portSettings</span><span class="p">)</span> <span class="o">!=</span> <span class="mi">0</span><span class="p">)</span></div><div class='line' id='LC114'>		<span class="k">return</span> <span class="n">vncp_convertNativeToVnErrorCode</span><span class="p">(</span><span class="n">errno</span><span class="p">);</span></div><div class='line' id='LC115'><br/></div><div class='line' id='LC116'>	<span class="n">newComPortHandle</span><span class="o">-&gt;</span><span class="n">comPortHandle</span> <span class="o">=</span> <span class="n">portFd</span><span class="p">;</span></div><div class='line' id='LC117'><br/></div><div class='line' id='LC118'>	<span class="k">return</span> <span class="n">VNERR_NO_ERROR</span><span class="p">;</span></div><div class='line' id='LC119'><span class="p">}</span></div><div class='line' id='LC120'><br/></div><div class='line' id='LC121'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_comPort_writeData</span><span class="p">(</span><span class="n">VN_HANDLE</span> <span class="n">comPortHandle</span><span class="p">,</span> <span class="kt">char</span> <span class="k">const</span><span class="o">*</span> <span class="n">dataToWrite</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">numOfBytesToWrite</span><span class="p">)</span></div><div class='line' id='LC122'><span class="p">{</span></div><div class='line' id='LC123'>	<span class="kt">int</span> <span class="n">errorCode</span><span class="p">;</span></div><div class='line' id='LC124'><br/></div><div class='line' id='LC125'>	<span class="n">errorCode</span> <span class="o">=</span> <span class="n">write</span><span class="p">(</span><span class="n">comPortHandle</span><span class="p">.</span><span class="n">comPortHandle</span><span class="p">,</span> <span class="n">dataToWrite</span><span class="p">,</span> <span class="n">numOfBytesToWrite</span><span class="p">);</span></div><div class='line' id='LC126'><br/></div><div class='line' id='LC127'>	<span class="k">if</span> <span class="p">(</span><span class="n">errorCode</span> <span class="o">==</span> <span class="o">-</span><span class="mi">1</span><span class="p">)</span></div><div class='line' id='LC128'>		<span class="k">return</span> <span class="n">vncp_convertNativeToVnErrorCode</span><span class="p">(</span><span class="n">errno</span><span class="p">);</span></div><div class='line' id='LC129'><br/></div><div class='line' id='LC130'>	<span class="k">return</span> <span class="n">VNERR_NO_ERROR</span><span class="p">;</span></div><div class='line' id='LC131'><span class="p">}</span></div><div class='line' id='LC132'><br/></div><div class='line' id='LC133'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_comPort_readData</span><span class="p">(</span><span class="n">VN_HANDLE</span> <span class="n">comPortHandle</span><span class="p">,</span> <span class="kt">char</span><span class="o">*</span> <span class="n">readBuffer</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">numOfBytesToRead</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span><span class="o">*</span> <span class="n">numOfBytesActuallyRead</span><span class="p">)</span></div><div class='line' id='LC134'><span class="p">{</span></div><div class='line' id='LC135'>	<span class="kt">int</span> <span class="n">numOfBytesRead</span><span class="p">;</span></div><div class='line' id='LC136'><br/></div><div class='line' id='LC137'>	<span class="o">*</span><span class="n">numOfBytesActuallyRead</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC138'><br/></div><div class='line' id='LC139'>	<span class="n">numOfBytesRead</span> <span class="o">=</span> <span class="n">read</span><span class="p">(</span><span class="n">comPortHandle</span><span class="p">.</span><span class="n">comPortHandle</span><span class="p">,</span> <span class="n">readBuffer</span><span class="p">,</span> <span class="n">numOfBytesToRead</span><span class="p">);</span></div><div class='line' id='LC140'><br/></div><div class='line' id='LC141'>	<span class="k">if</span> <span class="p">(</span><span class="n">numOfBytesRead</span> <span class="o">==</span> <span class="o">-</span><span class="mi">1</span><span class="p">)</span></div><div class='line' id='LC142'>		<span class="k">return</span> <span class="n">vncp_convertNativeToVnErrorCode</span><span class="p">(</span><span class="n">errno</span><span class="p">);</span></div><div class='line' id='LC143'><br/></div><div class='line' id='LC144'>	<span class="o">*</span><span class="n">numOfBytesActuallyRead</span> <span class="o">=</span> <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span> <span class="n">numOfBytesRead</span><span class="p">;</span></div><div class='line' id='LC145'><br/></div><div class='line' id='LC146'>	<span class="k">return</span> <span class="n">VNERR_NO_ERROR</span><span class="p">;</span></div><div class='line' id='LC147'><span class="p">}</span></div><div class='line' id='LC148'><br/></div><div class='line' id='LC149'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_comPort_close</span><span class="p">(</span><span class="n">VN_HANDLE</span> <span class="n">comPortHandle</span><span class="p">)</span></div><div class='line' id='LC150'><span class="p">{</span></div><div class='line' id='LC151'>	<span class="k">if</span> <span class="p">(</span><span class="n">close</span><span class="p">(</span><span class="n">comPortHandle</span><span class="p">.</span><span class="n">comPortHandle</span><span class="p">)</span> <span class="o">==</span> <span class="o">-</span><span class="mi">1</span><span class="p">)</span></div><div class='line' id='LC152'>		<span class="k">return</span> <span class="n">vncp_convertNativeToVnErrorCode</span><span class="p">(</span><span class="n">errno</span><span class="p">);</span></div><div class='line' id='LC153'><br/></div><div class='line' id='LC154'>	<span class="k">return</span> <span class="n">VNERR_NO_ERROR</span><span class="p">;</span></div><div class='line' id='LC155'><span class="p">}</span></div><div class='line' id='LC156'><br/></div><div class='line' id='LC157'><span class="kt">tcflag_t</span> <span class="nf">vncp_determineBaudrateFlag</span><span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">baudrate</span><span class="p">)</span></div><div class='line' id='LC158'><span class="p">{</span></div><div class='line' id='LC159'>	<span class="k">switch</span> <span class="p">(</span><span class="n">baudrate</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC160'>		<span class="k">case</span> <span class="mi">9600</span>:		<span class="k">return</span> <span class="n">B9600</span><span class="p">;</span></div><div class='line' id='LC161'>		<span class="k">case</span> <span class="mi">19200</span>:		<span class="k">return</span> <span class="n">B19200</span><span class="p">;</span></div><div class='line' id='LC162'>		<span class="k">case</span> <span class="mi">38400</span>:		<span class="k">return</span> <span class="n">B38400</span><span class="p">;</span></div><div class='line' id='LC163'>		<span class="k">case</span> <span class="mi">57600</span>:		<span class="k">return</span> <span class="n">B57600</span><span class="p">;</span></div><div class='line' id='LC164'>		<span class="k">case</span> <span class="mi">115200</span>:	<span class="k">return</span> <span class="n">B115200</span><span class="p">;</span></div><div class='line' id='LC165'>		<span class="k">case</span> <span class="mi">230400</span>:	<span class="k">return</span> <span class="n">B230400</span><span class="p">;</span></div><div class='line' id='LC166'>		<span class="k">case</span> <span class="mi">460800</span>:	<span class="k">return</span> <span class="n">B460800</span><span class="p">;</span></div><div class='line' id='LC167'>		<span class="k">case</span> <span class="mi">921600</span>:	<span class="k">return</span> <span class="n">B921600</span><span class="p">;</span></div><div class='line' id='LC168'>		<span class="nl">default:</span>		<span class="k">return</span> <span class="n">B0</span><span class="p">;</span></div><div class='line' id='LC169'>	<span class="p">}</span></div><div class='line' id='LC170'><span class="p">}</span></div><div class='line' id='LC171'><br/></div><div class='line' id='LC172'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_event_create</span><span class="p">(</span><span class="n">VN_HANDLE</span><span class="o">*</span> <span class="n">newEventHandle</span><span class="p">)</span></div><div class='line' id='LC173'><span class="p">{</span></div><div class='line' id='LC174'>	<span class="kt">int</span> <span class="n">errorCode</span><span class="p">;</span></div><div class='line' id='LC175'>	<span class="n">VncpConditionAndMutex</span><span class="o">*</span> <span class="n">cm</span><span class="p">;</span></div><div class='line' id='LC176'><br/></div><div class='line' id='LC177'>	<span class="n">cm</span> <span class="o">=</span> <span class="p">(</span><span class="n">VncpConditionAndMutex</span><span class="o">*</span><span class="p">)</span> <span class="n">malloc</span><span class="p">(</span><span class="k">sizeof</span><span class="p">(</span><span class="n">VncpConditionAndMutex</span><span class="p">));</span></div><div class='line' id='LC178'><br/></div><div class='line' id='LC179'>	<span class="n">errorCode</span> <span class="o">=</span> <span class="n">pthread_mutex_init</span><span class="p">(</span><span class="o">&amp;</span><span class="n">cm</span><span class="o">-&gt;</span><span class="n">mutex</span><span class="p">,</span> <span class="nb">NULL</span><span class="p">);</span></div><div class='line' id='LC180'><br/></div><div class='line' id='LC181'>	<span class="k">if</span> <span class="p">(</span><span class="n">errorCode</span> <span class="o">!=</span> <span class="mi">0</span><span class="p">)</span></div><div class='line' id='LC182'>		<span class="k">return</span> <span class="n">vncp_convertNativeToVnErrorCode</span><span class="p">(</span><span class="n">errorCode</span><span class="p">);</span></div><div class='line' id='LC183'><br/></div><div class='line' id='LC184'>	<span class="n">errorCode</span> <span class="o">=</span> <span class="n">pthread_cond_init</span><span class="p">(</span><span class="o">&amp;</span><span class="n">cm</span><span class="o">-&gt;</span><span class="n">condition</span><span class="p">,</span> <span class="nb">NULL</span><span class="p">);</span></div><div class='line' id='LC185'><br/></div><div class='line' id='LC186'>	<span class="k">if</span> <span class="p">(</span><span class="n">errorCode</span> <span class="o">!=</span> <span class="mi">0</span><span class="p">)</span></div><div class='line' id='LC187'>		<span class="k">return</span> <span class="n">vncp_convertNativeToVnErrorCode</span><span class="p">(</span><span class="n">errorCode</span><span class="p">);</span></div><div class='line' id='LC188'><br/></div><div class='line' id='LC189'>	<span class="n">cm</span><span class="o">-&gt;</span><span class="n">isTriggered</span> <span class="o">=</span> <span class="n">VN_FALSE</span><span class="p">;</span></div><div class='line' id='LC190'><br/></div><div class='line' id='LC191'>	<span class="n">newEventHandle</span><span class="o">-&gt;</span><span class="n">conditionAndMutexStruct</span> <span class="o">=</span> <span class="n">cm</span><span class="p">;</span></div><div class='line' id='LC192'><br/></div><div class='line' id='LC193'>	<span class="k">return</span> <span class="n">VNERR_NO_ERROR</span><span class="p">;</span></div><div class='line' id='LC194'><span class="p">}</span></div><div class='line' id='LC195'><br/></div><div class='line' id='LC196'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_event_waitFor</span><span class="p">(</span><span class="n">VN_HANDLE</span> <span class="n">eventHandle</span><span class="p">,</span> <span class="kt">int</span> <span class="n">timeout</span><span class="p">)</span></div><div class='line' id='LC197'><span class="p">{</span></div><div class='line' id='LC198'>	<span class="kt">int</span> <span class="n">errorCode</span><span class="p">,</span> <span class="n">loopErrorCode</span><span class="p">;</span></div><div class='line' id='LC199'>	<span class="n">VncpConditionAndMutex</span><span class="o">*</span> <span class="n">cm</span><span class="p">;</span></div><div class='line' id='LC200'>	<span class="k">struct</span> <span class="n">timespec</span> <span class="n">delta</span><span class="p">;</span></div><div class='line' id='LC201'>	<span class="k">struct</span> <span class="n">timespec</span> <span class="n">abstime</span><span class="p">;</span></div><div class='line' id='LC202'><br/></div><div class='line' id='LC203'>	<span class="c1">// Compute our timeout.</span></div><div class='line' id='LC204'>	<span class="k">if</span> <span class="p">(</span><span class="n">timeout</span> <span class="o">!=</span> <span class="o">-</span><span class="mi">1</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC205'><br/></div><div class='line' id='LC206'>		<span class="n">clock_gettime</span><span class="p">(</span><span class="n">CLOCK_REALTIME</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">abstime</span><span class="p">);</span></div><div class='line' id='LC207'><br/></div><div class='line' id='LC208'>		<span class="kt">int</span> <span class="n">nano</span> <span class="o">=</span> <span class="n">abstime</span><span class="p">.</span><span class="n">tv_nsec</span> <span class="o">+</span> <span class="p">(</span><span class="n">timeout</span> <span class="o">%</span> <span class="mi">1000</span><span class="p">)</span> <span class="o">*</span> <span class="mi">1000000</span><span class="p">;</span></div><div class='line' id='LC209'><br/></div><div class='line' id='LC210'>		<span class="n">delta</span><span class="p">.</span><span class="n">tv_nsec</span> <span class="o">=</span> <span class="n">nano</span> <span class="o">%</span> <span class="mi">1000000000</span><span class="p">;</span></div><div class='line' id='LC211'>		<span class="n">delta</span><span class="p">.</span><span class="n">tv_sec</span> <span class="o">=</span> <span class="n">abstime</span><span class="p">.</span><span class="n">tv_sec</span> <span class="o">+</span> <span class="n">timeout</span> <span class="o">/</span> <span class="mi">1000</span> <span class="o">+</span> <span class="n">nano</span> <span class="o">/</span> <span class="mi">1000000000</span><span class="p">;</span></div><div class='line' id='LC212'>	<span class="p">}</span></div><div class='line' id='LC213'><br/></div><div class='line' id='LC214'>	<span class="n">cm</span> <span class="o">=</span> <span class="p">(</span><span class="n">VncpConditionAndMutex</span><span class="o">*</span><span class="p">)</span> <span class="n">eventHandle</span><span class="p">.</span><span class="n">conditionAndMutexStruct</span><span class="p">;</span></div><div class='line' id='LC215'><br/></div><div class='line' id='LC216'>	<span class="n">errorCode</span> <span class="o">=</span> <span class="n">pthread_mutex_lock</span><span class="p">(</span><span class="o">&amp;</span><span class="n">cm</span><span class="o">-&gt;</span><span class="n">mutex</span><span class="p">);</span></div><div class='line' id='LC217'><br/></div><div class='line' id='LC218'>	<span class="k">if</span> <span class="p">(</span><span class="n">errorCode</span> <span class="o">!=</span> <span class="mi">0</span><span class="p">)</span></div><div class='line' id='LC219'>		<span class="k">return</span> <span class="n">vncp_convertNativeToVnErrorCode</span><span class="p">(</span><span class="n">errorCode</span><span class="p">);</span></div><div class='line' id='LC220'><br/></div><div class='line' id='LC221'>	<span class="k">while</span> <span class="p">(</span><span class="o">!</span><span class="n">cm</span><span class="o">-&gt;</span><span class="n">isTriggered</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC222'><br/></div><div class='line' id='LC223'>		<span class="k">if</span> <span class="p">(</span><span class="n">timeout</span> <span class="o">==</span> <span class="o">-</span><span class="mi">1</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC224'>			<span class="n">loopErrorCode</span> <span class="o">=</span> <span class="n">pthread_cond_wait</span><span class="p">(</span><span class="o">&amp;</span><span class="n">cm</span><span class="o">-&gt;</span><span class="n">condition</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">cm</span><span class="o">-&gt;</span><span class="n">mutex</span><span class="p">);</span></div><div class='line' id='LC225'><br/></div><div class='line' id='LC226'>			<span class="k">if</span> <span class="p">(</span><span class="n">loopErrorCode</span> <span class="o">!=</span> <span class="mi">0</span><span class="p">)</span></div><div class='line' id='LC227'>				<span class="k">return</span> <span class="n">vncp_convertNativeToVnErrorCode</span><span class="p">(</span><span class="n">loopErrorCode</span><span class="p">);</span></div><div class='line' id='LC228'>		<span class="p">}</span></div><div class='line' id='LC229'>		<span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC230'>			<span class="n">loopErrorCode</span> <span class="o">=</span> <span class="n">pthread_cond_timedwait</span><span class="p">(</span><span class="o">&amp;</span><span class="n">cm</span><span class="o">-&gt;</span><span class="n">condition</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">cm</span><span class="o">-&gt;</span><span class="n">mutex</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">delta</span><span class="p">);</span></div><div class='line' id='LC231'><br/></div><div class='line' id='LC232'>			<span class="k">if</span> <span class="p">(</span><span class="n">loopErrorCode</span> <span class="o">==</span> <span class="n">ETIMEDOUT</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC233'>				<span class="n">cm</span><span class="o">-&gt;</span><span class="n">isTriggered</span> <span class="o">=</span> <span class="n">VN_FALSE</span><span class="p">;</span></div><div class='line' id='LC234'>				<span class="n">errorCode</span> <span class="o">=</span> <span class="n">pthread_mutex_unlock</span><span class="p">(</span><span class="o">&amp;</span><span class="n">cm</span><span class="o">-&gt;</span><span class="n">mutex</span><span class="p">);</span></div><div class='line' id='LC235'><br/></div><div class='line' id='LC236'>				<span class="k">return</span> <span class="n">VNERR_TIMEOUT</span><span class="p">;</span></div><div class='line' id='LC237'>			<span class="p">}</span></div><div class='line' id='LC238'>		<span class="p">}</span></div><div class='line' id='LC239'>	<span class="p">}</span></div><div class='line' id='LC240'><br/></div><div class='line' id='LC241'>	<span class="n">cm</span><span class="o">-&gt;</span><span class="n">isTriggered</span> <span class="o">=</span> <span class="n">VN_FALSE</span><span class="p">;</span></div><div class='line' id='LC242'><br/></div><div class='line' id='LC243'>	<span class="n">errorCode</span> <span class="o">=</span> <span class="n">pthread_mutex_unlock</span><span class="p">(</span><span class="o">&amp;</span><span class="n">cm</span><span class="o">-&gt;</span><span class="n">mutex</span><span class="p">);</span></div><div class='line' id='LC244'><br/></div><div class='line' id='LC245'>	<span class="k">if</span> <span class="p">(</span><span class="n">errorCode</span> <span class="o">!=</span> <span class="mi">0</span><span class="p">)</span></div><div class='line' id='LC246'>		<span class="k">return</span> <span class="n">vncp_convertNativeToVnErrorCode</span><span class="p">(</span><span class="n">errorCode</span><span class="p">);</span></div><div class='line' id='LC247'><br/></div><div class='line' id='LC248'>	<span class="k">return</span> <span class="n">VNERR_NO_ERROR</span><span class="p">;</span></div><div class='line' id='LC249'><span class="p">}</span></div><div class='line' id='LC250'><br/></div><div class='line' id='LC251'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_event_signal</span><span class="p">(</span><span class="n">VN_HANDLE</span> <span class="n">eventHandle</span><span class="p">)</span></div><div class='line' id='LC252'><span class="p">{</span></div><div class='line' id='LC253'>	<span class="kt">int</span> <span class="n">errorCode</span><span class="p">;</span></div><div class='line' id='LC254'>	<span class="n">VncpConditionAndMutex</span><span class="o">*</span> <span class="n">cm</span><span class="p">;</span></div><div class='line' id='LC255'><br/></div><div class='line' id='LC256'>	<span class="n">cm</span> <span class="o">=</span> <span class="p">(</span><span class="n">VncpConditionAndMutex</span><span class="o">*</span><span class="p">)</span> <span class="n">eventHandle</span><span class="p">.</span><span class="n">conditionAndMutexStruct</span><span class="p">;</span></div><div class='line' id='LC257'><br/></div><div class='line' id='LC258'>	<span class="n">errorCode</span> <span class="o">=</span> <span class="n">pthread_mutex_lock</span><span class="p">(</span><span class="o">&amp;</span><span class="n">cm</span><span class="o">-&gt;</span><span class="n">mutex</span><span class="p">);</span></div><div class='line' id='LC259'><br/></div><div class='line' id='LC260'>	<span class="n">cm</span><span class="o">-&gt;</span><span class="n">isTriggered</span> <span class="o">=</span> <span class="n">VN_TRUE</span><span class="p">;</span></div><div class='line' id='LC261'><br/></div><div class='line' id='LC262'>	<span class="k">if</span> <span class="p">(</span><span class="n">errorCode</span> <span class="o">!=</span> <span class="mi">0</span><span class="p">)</span></div><div class='line' id='LC263'>		<span class="k">return</span> <span class="n">vncp_convertNativeToVnErrorCode</span><span class="p">(</span><span class="n">errorCode</span><span class="p">);</span></div><div class='line' id='LC264'><br/></div><div class='line' id='LC265'>	<span class="n">errorCode</span> <span class="o">=</span> <span class="n">pthread_cond_signal</span><span class="p">(</span><span class="o">&amp;</span><span class="n">cm</span><span class="o">-&gt;</span><span class="n">condition</span><span class="p">);</span></div><div class='line' id='LC266'><br/></div><div class='line' id='LC267'>	<span class="k">if</span> <span class="p">(</span><span class="n">errorCode</span> <span class="o">!=</span> <span class="mi">0</span><span class="p">)</span></div><div class='line' id='LC268'>		<span class="k">return</span> <span class="n">vncp_convertNativeToVnErrorCode</span><span class="p">(</span><span class="n">errorCode</span><span class="p">);</span></div><div class='line' id='LC269'><br/></div><div class='line' id='LC270'>	<span class="n">errorCode</span> <span class="o">=</span> <span class="n">pthread_mutex_unlock</span><span class="p">(</span><span class="o">&amp;</span><span class="n">cm</span><span class="o">-&gt;</span><span class="n">mutex</span><span class="p">);</span></div><div class='line' id='LC271'><br/></div><div class='line' id='LC272'>	<span class="k">if</span> <span class="p">(</span><span class="n">errorCode</span> <span class="o">!=</span> <span class="mi">0</span><span class="p">)</span></div><div class='line' id='LC273'>		<span class="k">return</span> <span class="n">vncp_convertNativeToVnErrorCode</span><span class="p">(</span><span class="n">errorCode</span><span class="p">);</span></div><div class='line' id='LC274'><br/></div><div class='line' id='LC275'>	<span class="k">return</span> <span class="n">VNERR_NO_ERROR</span><span class="p">;</span></div><div class='line' id='LC276'><span class="p">}</span></div><div class='line' id='LC277'><br/></div><div class='line' id='LC278'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_criticalSection_initialize</span><span class="p">(</span><span class="n">VN_CRITICAL_SECTION</span><span class="o">*</span> <span class="n">criticalSection</span><span class="p">)</span></div><div class='line' id='LC279'><span class="p">{</span></div><div class='line' id='LC280'>	<span class="kt">int</span> <span class="n">errorCode</span><span class="p">;</span></div><div class='line' id='LC281'><br/></div><div class='line' id='LC282'>	<span class="n">errorCode</span> <span class="o">=</span> <span class="n">pthread_mutex_init</span><span class="p">(</span><span class="n">criticalSection</span><span class="p">,</span> <span class="nb">NULL</span><span class="p">);</span></div><div class='line' id='LC283'><br/></div><div class='line' id='LC284'>	<span class="k">if</span> <span class="p">(</span><span class="n">errorCode</span> <span class="o">!=</span> <span class="mi">0</span><span class="p">)</span></div><div class='line' id='LC285'>		<span class="k">return</span> <span class="n">vncp_convertNativeToVnErrorCode</span><span class="p">(</span><span class="n">errorCode</span><span class="p">);</span></div><div class='line' id='LC286'><br/></div><div class='line' id='LC287'>	<span class="k">return</span> <span class="n">VNERR_NO_ERROR</span><span class="p">;</span></div><div class='line' id='LC288'><span class="p">}</span></div><div class='line' id='LC289'><br/></div><div class='line' id='LC290'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_criticalSection_enter</span><span class="p">(</span><span class="n">VN_CRITICAL_SECTION</span><span class="o">*</span> <span class="n">criticalSection</span><span class="p">)</span></div><div class='line' id='LC291'><span class="p">{</span></div><div class='line' id='LC292'>	<span class="kt">int</span> <span class="n">errorCode</span><span class="p">;</span></div><div class='line' id='LC293'><br/></div><div class='line' id='LC294'>	<span class="n">errorCode</span> <span class="o">=</span> <span class="n">pthread_mutex_lock</span><span class="p">(</span><span class="n">criticalSection</span><span class="p">);</span></div><div class='line' id='LC295'><br/></div><div class='line' id='LC296'>	<span class="k">if</span> <span class="p">(</span><span class="n">errorCode</span> <span class="o">!=</span> <span class="mi">0</span><span class="p">)</span></div><div class='line' id='LC297'>		<span class="k">return</span> <span class="n">vncp_convertNativeToVnErrorCode</span><span class="p">(</span><span class="n">errorCode</span><span class="p">);</span></div><div class='line' id='LC298'><br/></div><div class='line' id='LC299'>	<span class="k">return</span> <span class="n">VNERR_NO_ERROR</span><span class="p">;</span></div><div class='line' id='LC300'><span class="p">}</span></div><div class='line' id='LC301'><br/></div><div class='line' id='LC302'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_criticalSection_leave</span><span class="p">(</span><span class="n">VN_CRITICAL_SECTION</span><span class="o">*</span> <span class="n">criticalSection</span><span class="p">)</span></div><div class='line' id='LC303'><span class="p">{</span></div><div class='line' id='LC304'>	<span class="kt">int</span> <span class="n">errorCode</span><span class="p">;</span></div><div class='line' id='LC305'><br/></div><div class='line' id='LC306'>	<span class="n">errorCode</span> <span class="o">=</span> <span class="n">pthread_mutex_unlock</span><span class="p">(</span><span class="n">criticalSection</span><span class="p">);</span></div><div class='line' id='LC307'><br/></div><div class='line' id='LC308'>	<span class="k">if</span> <span class="p">(</span><span class="n">errorCode</span> <span class="o">!=</span> <span class="mi">0</span><span class="p">)</span></div><div class='line' id='LC309'>		<span class="k">return</span> <span class="n">vncp_convertNativeToVnErrorCode</span><span class="p">(</span><span class="n">errorCode</span><span class="p">);</span></div><div class='line' id='LC310'><br/></div><div class='line' id='LC311'>	<span class="k">return</span> <span class="n">VNERR_NO_ERROR</span><span class="p">;</span></div><div class='line' id='LC312'><span class="p">}</span></div><div class='line' id='LC313'><br/></div><div class='line' id='LC314'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_criticalSection_dispose</span><span class="p">(</span><span class="n">VN_CRITICAL_SECTION</span><span class="o">*</span> <span class="n">criticalSection</span><span class="p">)</span></div><div class='line' id='LC315'><span class="p">{</span></div><div class='line' id='LC316'>	<span class="kt">int</span> <span class="n">errorCode</span><span class="p">;</span></div><div class='line' id='LC317'><br/></div><div class='line' id='LC318'>	<span class="n">errorCode</span> <span class="o">=</span> <span class="n">pthread_mutex_destroy</span><span class="p">(</span><span class="n">criticalSection</span><span class="p">);</span></div><div class='line' id='LC319'><br/></div><div class='line' id='LC320'>	<span class="k">if</span> <span class="p">(</span><span class="n">errorCode</span> <span class="o">!=</span> <span class="mi">0</span><span class="p">)</span></div><div class='line' id='LC321'>		<span class="k">return</span> <span class="n">vncp_convertNativeToVnErrorCode</span><span class="p">(</span><span class="n">errorCode</span><span class="p">);</span></div><div class='line' id='LC322'><br/></div><div class='line' id='LC323'>	<span class="k">return</span> <span class="n">VNERR_NO_ERROR</span><span class="p">;</span></div><div class='line' id='LC324'><span class="p">}</span></div><div class='line' id='LC325'><br/></div><div class='line' id='LC326'><span class="kt">void</span><span class="o">*</span> <span class="nf">vncp_thread_startRoutine</span><span class="p">(</span><span class="kt">void</span><span class="o">*</span> <span class="n">threadStartData</span><span class="p">)</span></div><div class='line' id='LC327'><span class="p">{</span></div><div class='line' id='LC328'>	<span class="n">VncpThreadStartData</span><span class="o">*</span> <span class="n">data</span><span class="p">;</span></div><div class='line' id='LC329'><br/></div><div class='line' id='LC330'>	<span class="n">data</span> <span class="o">=</span> <span class="p">(</span><span class="n">VncpThreadStartData</span><span class="o">*</span><span class="p">)</span> <span class="n">threadStartData</span><span class="p">;</span></div><div class='line' id='LC331'><br/></div><div class='line' id='LC332'>	<span class="cm">/* Call the user&#39;s thread routine. */</span></div><div class='line' id='LC333'>	<span class="n">data</span><span class="o">-&gt;</span><span class="n">startRoutine</span><span class="p">(</span><span class="n">data</span><span class="o">-&gt;</span><span class="n">routineData</span><span class="p">);</span></div><div class='line' id='LC334'><br/></div><div class='line' id='LC335'>	<span class="k">return</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC336'><span class="p">}</span></div><div class='line' id='LC337'><br/></div><div class='line' id='LC338'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_convertNativeToVnErrorCode</span><span class="p">(</span><span class="kt">int</span> <span class="n">nativeErrorCode</span><span class="p">)</span></div><div class='line' id='LC339'><span class="p">{</span></div><div class='line' id='LC340'>	<span class="k">switch</span> <span class="p">(</span><span class="n">nativeErrorCode</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC341'><br/></div><div class='line' id='LC342'>		<span class="k">case</span> <span class="n">ENOENT</span>:</div><div class='line' id='LC343'>			<span class="k">return</span> <span class="n">VNERR_FILE_NOT_FOUND</span><span class="p">;</span></div><div class='line' id='LC344'><br/></div><div class='line' id='LC345'>		<span class="nl">default:</span></div><div class='line' id='LC346'>			<span class="k">return</span> <span class="n">VNERR_UNKNOWN_ERROR</span><span class="p">;</span></div><div class='line' id='LC347'>	<span class="p">}</span></div><div class='line' id='LC348'><span class="p">}</span></div><div class='line' id='LC349'><br/></div><div class='line' id='LC350'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_sleepInMs</span><span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">numOfMillisecondsToSleep</span><span class="p">)</span></div><div class='line' id='LC351'><span class="p">{</span></div><div class='line' id='LC352'>	<span class="n">usleep</span><span class="p">(</span><span class="n">numOfMillisecondsToSleep</span> <span class="o">*</span> <span class="mi">1000</span><span class="p">);</span></div><div class='line' id='LC353'><br/></div><div class='line' id='LC354'>	<span class="k">return</span> <span class="n">VNERR_NO_ERROR</span><span class="p">;</span></div><div class='line' id='LC355'><span class="p">}</span></div><div class='line' id='LC356'><br/></div><div class='line' id='LC357'><span class="cm">/** \endcond */</span></div></pre></div>
          </td>
        </tr>
      </table>
  </div>

          </div>
        </div>

        <a href="#jump-to-line" rel="facebox" data-hotkey="l" class="js-jump-to-line" style="display:none">Jump to Line</a>
        <div id="jump-to-line" style="display:none">
          <h2>Jump to Line</h2>
          <form accept-charset="UTF-8" class="js-jump-to-line-form">
            <input class="textfield js-jump-to-line-field" type="text">
            <div class="full-button">
              <button type="submit" class="button">Go</button>
            </div>
          </form>
        </div>

      </div>
    </div>
</div>

<div id="js-frame-loading-template" class="frame frame-loading large-loading-area" style="display:none;">
  <img class="js-frame-loading-spinner" src="https://a248.e.akamai.net/assets.github.com/images/spinners/octocat-spinner-128.gif?1347543527" height="64" width="64">
</div>


        </div>
      </div>
      <div class="modal-backdrop"></div>
    </div>

      <div id="footer-push"></div><!-- hack for sticky footer -->
    </div><!-- end of wrapper - hack for sticky footer -->

      <!-- footer -->
      <div id="footer">
  <div class="container clearfix">

      <dl class="footer_nav">
        <dt>GitHub</dt>
        <dd><a href="https://github.com/about">About us</a></dd>
        <dd><a href="https://github.com/blog">Blog</a></dd>
        <dd><a href="https://github.com/contact">Contact &amp; support</a></dd>
        <dd><a href="http://enterprise.github.com/">GitHub Enterprise</a></dd>
        <dd><a href="http://status.github.com/">Site status</a></dd>
      </dl>

      <dl class="footer_nav">
        <dt>Applications</dt>
        <dd><a href="http://mac.github.com/">GitHub for Mac</a></dd>
        <dd><a href="http://windows.github.com/">GitHub for Windows</a></dd>
        <dd><a href="http://eclipse.github.com/">GitHub for Eclipse</a></dd>
        <dd><a href="http://mobile.github.com/">GitHub mobile apps</a></dd>
      </dl>

      <dl class="footer_nav">
        <dt>Services</dt>
        <dd><a href="http://get.gaug.es/">Gauges: Web analytics</a></dd>
        <dd><a href="http://speakerdeck.com">Speaker Deck: Presentations</a></dd>
        <dd><a href="https://gist.github.com">Gist: Code snippets</a></dd>
        <dd><a href="http://jobs.github.com/">Job board</a></dd>
      </dl>

      <dl class="footer_nav">
        <dt>Documentation</dt>
        <dd><a href="http://help.github.com/">GitHub Help</a></dd>
        <dd><a href="http://developer.github.com/">Developer API</a></dd>
        <dd><a href="http://github.github.com/github-flavored-markdown/">GitHub Flavored Markdown</a></dd>
        <dd><a href="http://pages.github.com/">GitHub Pages</a></dd>
      </dl>

      <dl class="footer_nav">
        <dt>More</dt>
        <dd><a href="http://training.github.com/">Training</a></dd>
        <dd><a href="https://github.com/edu">Students &amp; teachers</a></dd>
        <dd><a href="http://shop.github.com">The Shop</a></dd>
        <dd><a href="/plans">Plans &amp; pricing</a></dd>
        <dd><a href="http://octodex.github.com/">The Octodex</a></dd>
      </dl>

      <hr class="footer-divider">


    <p class="right">&copy; 2013 <span title="0.15938s from fe18.rs.github.com">GitHub</span>, Inc. All rights reserved.</p>
    <a class="left" href="https://github.com/">
      <span class="mega-icon mega-icon-invertocat"></span>
    </a>
    <ul id="legal">
        <li><a href="https://github.com/site/terms">Terms of Service</a></li>
        <li><a href="https://github.com/site/privacy">Privacy</a></li>
        <li><a href="https://github.com/security">Security</a></li>
    </ul>

  </div><!-- /.container -->

</div><!-- /.#footer -->


    <div class="fullscreen-overlay js-fullscreen-overlay" id="fullscreen_overlay">
  <div class="fullscreen-container js-fullscreen-container">
    <div class="textarea-wrap">
      <textarea name="fullscreen-contents" id="fullscreen-contents" class="js-fullscreen-contents" placeholder="" data-suggester="fullscreen_suggester"></textarea>
          <div class="suggester-container">
              <div class="suggester fullscreen-suggester js-navigation-container" id="fullscreen_suggester"
                 data-url="/alexsleat/projectChimaera/suggestions/commit">
              </div>
          </div>
    </div>
  </div>
  <div class="fullscreen-sidebar">
    <a href="#" class="exit-fullscreen js-exit-fullscreen tooltipped leftwards" title="Exit Zen Mode">
      <span class="mega-icon mega-icon-normalscreen"></span>
    </a>
    <a href="#" class="theme-switcher js-theme-switcher tooltipped leftwards"
      title="Switch themes">
      <span class="mini-icon mini-icon-brightness"></span>
    </a>
  </div>
</div>



    <div id="ajax-error-message" class="flash flash-error">
      <span class="mini-icon mini-icon-exclamation"></span>
      Something went wrong with that request. Please try again.
      <a href="#" class="mini-icon mini-icon-remove-close ajax-error-dismiss"></a>
    </div>

    
    
    <span id='server_response_time' data-time='0.15988' data-host='fe18'></span>
    
  </body>
</html>

